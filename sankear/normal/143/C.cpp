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

const ll inf = (ll)1e15;

int n;
ll ans1, ans2;

inline void solve(int a, int b){
	for(int i = 1; i * i <= b; i++){
		if(b % i == 0){
			ll res = (ll)(a + 1) * (i + 2) * (b / i + 2);
			ans1 = min(ans1, res - n);
			ans2 = max(ans2, res - n);
		}
	}
}

int main(){
	//freopen("covertexts.in", "r", stdin);
	//freopen("covertexts.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	ans1 = inf;
	ans2 = -inf;
	for(int i = 1; i * i <= n; i++){
		if(n % i == 0){
			solve(i, n / i);
			solve(n / i, i);
		}
	}
	cout << ans1 << " " << ans2 << endl;
	return 0;
}