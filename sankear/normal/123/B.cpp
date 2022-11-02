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

inline ll calc(ll a, ll b){
	if(a >= 0){
		return a / b;
	}
	return -((-a) / b + 1);
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ll a, b, x1, y1, x2, y2;
	scanf("%I64d %I64d %I64d %I64d %I64d %I64d", &a, &b, &x1, &y1, &x2, &y2);
	ll ans = max(abs(calc(x1 + y1, 2 * a) - calc(x2 + y2, 2 * a)), abs(calc(x1 - y1, 2 * b) - calc(x2 - y2, 2 * b)));
	printf("%I64d\n", ans);
	return 0;
}