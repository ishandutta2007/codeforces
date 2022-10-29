#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

#define maxn 5000

const long long mod = 1000000007;

long long mult[maxn];
int n;
int k;
int a[maxn], s[maxn];
long long a1[maxn];
long long cp;

long long invmod(long long aa){
	long long res(1), tmp(aa), powr(mod - 2);
	while(powr){
		if(powr % 2){
			--powr;
			res = (res * tmp) % mod;
		}
		powr /= 2;
		tmp = (tmp * tmp) % mod;
	}
	return res;
}

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &a[i]);
		a1[i] = a[i];
	}
	if(k == 0){
		for(int i = 1; i <= n; ++i)
			printf("%d ", a[i]);
		printf("\n");
		return 0;
	}
	mult[1] = 1;
	long long cur = k;
	for(int i = 2; i <= n; ++i){
		mult[i] = (mult[i - 1] * invmod(i - 1)) % mod;
		mult[i] = (mult[i] * cur) % mod;
		//printf("mult[%d] = %d\n", i, mult[i]);
		cur += 1;
	}
	for(int i = 1; i <= n; ++i){
		cp = 0;
		for(int j = 1; j <= i; ++j)
			cp = (cp + mult[j] * a1[i - j + 1]) % mod;
		s[i] = cp;
		printf("%d ", s[i]);
	}
	printf("\n");
	return 0;
}