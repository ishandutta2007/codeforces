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

typedef long long ll;

struct tp{
	ll x, y;
};

int res[300];
tp p[300], v[300];
int ans[1000100];

inline ll gcd(ll a, ll b){
	while(b > 0){
		a %= b;
		swap(a, b);
	}
	return a;
}

inline void norm(tp &v){
	if(v.x < 0 || (v.x == 0 && v.y < 0)){
		v.x = -v.x;
		v.y = -v.y;
	}
	ll g = gcd(abs(v.x), abs(v.y));
	v.x /= g;
	v.y /= g;
}

bool operator < (const tp &a, const tp &b){
	if(a.x != b.x){
		return a.x < b.x;
	}
	return a.y < b.y;
}

bool operator == (const tp &a, const tp &b){
	return a.x == b.x && a.y == b.y;
}

int main(){
	//freopen("chart.in", "r", stdin);
	//freopen("chart.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> p[i].x >> p[i].y;
	}
	for(int i = 1; i <= n; i++){
		ans[i] = 1;
	}
	for(int i = 0; i < m; i++){
		int sz = 0;
		for(int j = 0; j < m; j++){
			if(i != j){
				v[sz].x = p[j].x - p[i].x;
				v[sz].y = p[j].y - p[i].y;
				norm(v[sz++]);
			}
		}
		sort(v, v + sz);
		sz = unique(v, v + sz) - v;
		for(int j = 0; j < sz; j++){
			res[j] = 1;
		}
		for(int j = 0; j < m; j++){
			if(i != j){
				tp cur;
				cur.x = p[j].x - p[i].x;
				cur.y = p[j].y - p[i].y;
				norm(cur);
				res[lower_bound(v, v + sz, cur) - v]++;
			}
		}
		for(int j = 0; j < sz; j++){
			if(v[j].y == 0){
				continue;
			}
			ll k = (-p[i].y) / v[j].y;
			if(p[i].y + k * v[j].y != 0){
				continue;
			}
			ll x = p[i].x + k * v[j].x;
			if(x < 1 || x > n){
				continue;
			}
			ans[x] = max(ans[x], res[j]);
		}
	}
	ll sum = 0;
	for(int i = 1; i <= n; i++){
		sum += ans[i];
	}
	cout << sum << endl;
	return 0;
}