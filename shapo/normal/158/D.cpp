#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <functional>

#define maxn 50000

using namespace std;

int n;
int res;
int t[maxn];

int main(){
	res = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &t[i]);
		res += t[i];
	}
	
	for(int i = 3; i <= n; ++i)
		if(n % i == 0){
			int j = n / i;
			for(int l = 1; l <= j; ++l){
				int p = l, cur = 0;
				while(p <= n){
					cur += t[p];
					p += j;
				}
				if(cur > res)res = cur;
			}
		}
	
	printf("%d\n", res);
	return 0;
}