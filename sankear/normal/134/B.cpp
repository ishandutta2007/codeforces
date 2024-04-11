#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <complex>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex <double> tc;

const int inf = (int)1e9;

inline int gcd(int a, int b){
	while(b > 0){
		a %= b;
		swap(a, b);
	}
	return a;
}

inline int solve(int a, int b){
	if(a == 1 && b == 1){
		return 0;
	}
	if(a > b){
		return solve(a - b, b) + 1;
	}
	return solve(a, b - a) + 1;
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	int ans = inf;
	for(int i = 1; i <= n; i++){
		if(gcd(i, n) == 1){
			ans = min(ans, solve(i, n));
		}
	}
	printf("%d\n", ans);
	return 0;
}