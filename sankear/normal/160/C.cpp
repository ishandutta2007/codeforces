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

int n;
ll a[100100];

inline ll solve1(ll x){
	ll res = 0;
	for(int i = 0; i < n; i++){
		if(a[i] > x){
			break;
		}
		res += n;
	}
	return res;
}

inline ll solve2(ll x, ll y){
	int pos = -1;
	for(int i = 0; i < n; i++){
		if(a[i] > y){
			break;
		}
		pos = i;
	}
	ll res = 0;
	for(int i = 0; i < n; i++){
		if(a[i] == x){
			res += pos + 1;
		}
	}
	return res;
}

int main(){
    //freopen("amoeba.in", "r", stdin);
    //freopen("amoeba.out", "w", stdout);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ll k;
	scanf("%d %I64d", &n, &k);
	for(int i = 0; i < n; i++){
		scanf("%I64d", &a[i]);
	}
	sort(a, a + n);
	ll aa, l = -inf, r = inf;
	while(l <= r){
		ll mid = (l + r) / 2;
		if(solve1(mid) >= k){
			aa = mid;
			r = mid - 1;
		}
		else{
			l = mid + 1;
		}
	}
	k -= solve1(aa - 1);
	ll bb;
	l = -inf;
	r = inf;
	while(l <= r){
		ll mid = (l + r) / 2;
		if(solve2(aa, mid) >= k){
			bb = mid;
			r = mid - 1;
		}
		else{
			l = mid + 1;
		}
	}
	printf("%I64d %I64d\n", aa, bb);
	return 0;
}