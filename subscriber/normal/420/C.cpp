#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#include<cstring>
#define mp make_pair
#define pb push_back      
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define M 1000000007
using namespace std;
typedef pair<int,int> pt;

int n, p;
int x[755000], y[755000], h[755000], s[755000];
vector<int> v[755000];

int add(int x, int v) {
	x++;
	while (x <= n + 1) {
		s[x] += v;
		x = x + x - (x & (x - 1));
	}
}

int fin(int x) {
	int r = 0;
	x++;
	while (x > 0) {
		r += s[x];
		x &= x - 1;
	}
	return r;
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);
	cin >> n >> p;
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &x[i], &y[i]);
		x[i]--;
		y[i]--;
		h[x[i]]++;
		h[y[i]]++;
		v[x[i]].pb(i);
		v[y[i]].pb(i);
	}
	for (int i = 0; i < n; i++) add(h[i], 1);
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			int id = v[i][j];
			add(h[x[id]], -1);
			add(h[y[id]], -1);
			h[x[id]]--;
			h[y[id]]--;
			add(h[x[id]], 1);
			add(h[y[id]], 1);
		}
		int need = p - (int)v[i].size();
		int ad = n;
		if (need > 0) ad = n - fin(need - 1);
		if (h[i] >= need) ad--;
//	cout << ad << endl;
		ans += ad;
		for (int j = 0; j < v[i].size(); j++) {
			int id = v[i][j];
			add(h[x[id]], -1);
			add(h[y[id]], -1);
			h[x[id]]++;
			h[y[id]]++;
			add(h[x[id]], 1);
			add(h[y[id]], 1);
		}
	}
	cout << ans / 2 << endl;
	return 0;
}