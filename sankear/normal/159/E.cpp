#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <complex>

using namespace std;

#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair <int, int> pii;

const ll inf = (ll)1e15;

struct tp{
	int a, c;
	ll b;
};

struct tr{
	ll val;
	int num;
};

int maxv;
int c[100100], s[100100], a[100100];
vector <pii> v[100100];
vector <int> pos[100100];
tp p[100100];
tr rmq[280280];

bool operator < (const tp &a, const tp &b){
	return a.a < b.a;
}

bool operator < (const tr &a, const tr &b){
	return a.val < b.val;
}

inline tr getmax(int l, int r){
	tr res;
	res.val = -inf;
	l += maxv;
	r += maxv;
	while(l <= r){
		res = max(res, rmq[l]);
		l = (l + 1) / 2;
		res = max(res, rmq[r]);
		r = (r - 1) / 2;
	}
	return res;
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d %d", &c[i], &s[i]);
	}
	for(int i = 0; i < n; i++){
		a[i] = c[i];
	}
	sort(a, a + n);
	int k = unique(a, a + n) - a;
	for(int i = 0; i < n; i++){
		v[lower_bound(a, a + k, c[i]) - a].pb(mp(s[i], i));
	}
	int sz = 0;
	for(int i = 0; i < k; i++){
		sort(v[i].rbegin(), v[i].rend());
		pos[i].resize(v[i].size());
		ll sum = 0;
		for(int j = 0; j < (int)v[i].size(); j++){
			sum += v[i][j].first;
			p[sz].a = j + 1;
			p[sz].b = sum;
			p[sz++].c = i;
		}
	}
	sort(p, p + sz);
	for(int i = 0; i < sz; i++){
		pos[p[i].c][p[i].a - 1] = i;
	}
	maxv = 1;
	while(maxv < sz){
		maxv *= 2;
	}
	for(int i = 0; i < sz; i++){
		rmq[i + maxv].val = p[i].b;
		rmq[i + maxv].num = i;
	}
	for(int i = sz; i < maxv; i++){
		rmq[i + maxv].val = -inf;
		rmq[i + maxv].num = i;
	}
	for(int i = maxv - 1; i > 0; i--){
		rmq[i] = max(rmq[i * 2], rmq[i * 2 + 1]);
	}
	ll bestans = 0;
	int num1, num2;
	for(int i = 0; i < sz; i++){
		int gl = -1, l = 0, r = sz - 1;
		while(l <= r){
			int mid = (l + r) / 2;
			if(p[mid].a >= p[i].a){
				gl = mid;
				r = mid - 1;
			}
			else{
				l = mid + 1;
			}
		}
		int gr = gl;
		l = gl + 1, r = sz - 1;
		while(l <= r){
			int mid = (l + r) / 2;
			if(p[mid].a <= p[i].a + 1){
				gr = mid;
				l = mid + 1;
			}
			else{
				r = mid - 1;
			}
		}
		tr cur;
		if(v[p[i].c].size() > p[i].a){
			cur = max(getmax(gl, i - 1), max(getmax(i + 1, pos[p[i].c][p[i].a] - 1), getmax(pos[p[i].c][p[i].a] + 1, gr)));
		}
		else{
		    cur = max(getmax(gl, i - 1), getmax(i + 1, gr));
		}
		if(cur.val + p[i].b > bestans){
			bestans = cur.val + p[i].b;
			num1 = i;
			num2 = cur.num;
		}
	}
	vector <int> lst1, lst2;
	for(int i = 0; i < p[num1].a; i++){
		lst1.pb(v[p[num1].c][i].second);
	}
	for(int i = 0; i < p[num2].a; i++){
		lst2.pb(v[p[num2].c][i].second);
	}
	vector <int> ans;
	if(lst1.size() < lst2.size()){
		for(int i = 0; i < (int)lst1.size(); i++){
			ans.pb(lst2[i]);
			ans.pb(lst1[i]);
		}
		if(lst2.size() > lst1.size()){
			ans.pb(lst2[lst2.size() - 1]);
		}
	}
	else{
		for(int i = 0; i < (int)lst2.size(); i++){
			ans.pb(lst1[i]);
			ans.pb(lst2[i]);
		}
		if(lst1.size() > lst2.size()){
			ans.pb(lst1[lst1.size() - 1]);
		}
	}
	cout << bestans << endl;
	printf("%d\n", ans.size());
	for(int i = 0; i < ans.size(); i++){
		if(i > 0){
			printf(" ");
		}
		printf("%d", ans[i] + 1);
	}
	printf("\n");
	return 0;
}