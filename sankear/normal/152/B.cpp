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

const ll inf = (ll)2e9;

int n, m;

inline bool good(ll x, ll y){
	return x >= 1 && x <= n && y >= 1 && y <= m;
}

int main(){
	//freopen("anti.in", "r", stdin);
	//freopen("anti.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int k;
	ll x, y;
	scanf("%d %d %I64d %I64d %d", &n, &m, &x, &y, &k);
	ll ans = 0;
	for(int i = 0; i < k; i++){
		ll vx, vy;
		scanf("%I64d %I64d", &vx, &vy);
		ll res = 0, l = 1, r = inf;
		while(l <= r){
			ll mid = (l + r) / 2;
			if(good(x + vx * mid, y + vy * mid)){
				res = mid;
				l = mid + 1;
			}
			else{
				r = mid - 1;
			}
		}
		x += res * vx;
		y += res * vy;
		ans += res;
	}
	printf("%I64d\n", ans);
	return 0;
}