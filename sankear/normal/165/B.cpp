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
#include <queue>
#include <deque>
#include <functional>

using namespace std;

typedef long long ll;

const ll inf = (ll)1e17;

int main(){
	//freopen("caravans.in", "r", stdin);
	//freopen("caravans.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ll n, k;
	cin >> n >> k;
	ll ans, l = 1, r = inf;
	while(l <= r){
		ll mid = (l + r) / 2;
		ll cur = 1, sum = 0;
		while(sum < n && cur <= mid){
			sum += mid / cur;
			cur *= k;
		}
		if(sum >= n){
			ans = mid;
			r = mid - 1;
		}
		else{
			l = mid + 1;
		}
	}
	cout << ans << endl;
	return 0;
}