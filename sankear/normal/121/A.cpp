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

int sz;
ll lst[100100];

void gen(int x, ll y, int z){
	if(x > z){
		lst[sz++] = y;
		return;
	}
	gen(x + 1, y * 10 + 4, z);
	gen(x + 1, y * 10 + 7, z);
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
  ll l, r;
	scanf("%I64d %I64d", &l, &r);
	sz = 0;
	for(int i = 1; i <= 10; i++){
		gen(1, 0, i);
	}
	ll ans = 0;
	for(int i = 0; i < sz; i++){
		if(lst[i] >= l){
			ans += (ll)lst[i] * (min(r, lst[i]) - l + 1);
			l = lst[i] + 1;
			if(l > r){
				break;
			}
		}
	}
	printf("%I64d\n", ans);
	return 0;
}