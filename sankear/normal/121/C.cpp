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

int n, sz;
bool used[2000];
int lst[2000];
ll f[2000];

void gen(int x, ll y, int z){
	if(x > z){
		if(y <= n){
			lst[sz++] = y;
		}
		return;
	}
	gen(x + 1, y * 10 + 4, z);
	gen(x + 1, y * 10 + 7, z);
}

inline bool good(int a){
	while(a > 0){
		int b = a % 10;
		if(b != 4 && b != 7){
			return false;
		}
		a /= 10;
	}
	return true;
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
  ll k;
	scanf("%d %I64d", &n, &k);
	if(n <= 15){
		ll all = 1;
		for(int i = 2; i <= n; i++){
			all *= i;
		}
		if(all < k){
			printf("-1\n");
			return 0;
		}
	}
	f[0] = 1;
	for(int i = 1; i <= 15; i++){
		f[i] = f[i - 1] * i;
	}
	int ans = 0;
	for(int i = max(n - 15, 1); i <= n; i++){
		for(int j = max(n - 15, 1); j <= n; j++){
			if(!used[j - max(n - 15, 1)]){
				if(f[n - i] < k){
					k -= f[n - i];
					continue;
				}
				used[j - max(n - 15, 1)] = true;
				if(good(i) && good(j)){
					ans++;
				}
				break;
			}
		}
	}
	sz = 0;
	for(int i = 1; i <= 10; i++){
		gen(1, 0, i);
	}
	for(int i = 0; i < sz; i++){
		if(lst[i] < n - 15){
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}