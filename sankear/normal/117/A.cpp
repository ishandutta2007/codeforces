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

using namespace std;

typedef long long ll;
typedef long double ld;

ll m;

inline ll get(ll a, ll b){
	ll k = b / (2 * (m - 1));
	ll t = 2 * k * (m - 1);
	b -= t;
	if(b <= m - 1){
	  if(a >= b + 1){
			return t + a - 1;
		}
		return t + 2 * m - a - 1;
	}
	b -= m - 1;
	if(a <= m - b){
		return t + 2 * m - a - 1;
	}
	return t + 2 * m + a - 3;
}

int main(){
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  int n;
	scanf("%d %I64d", &n, &m);
	for(int i = 0; i < n; i++){
		ll s, f, t;
		scanf("%I64d %I64d %I64d", &s, &f, &t);
		if(s == f){
			printf("%I64d\n", t);
			continue;
		}
		printf("%I64d\n", get(f, get(s, t)));
	}
  return 0;
}