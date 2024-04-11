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

#define maxn 110

unsigned long long ff[maxn];

int k, s;
int res;
int ans[maxn];

int main(){
	scanf("%d%d", &s, &k);
	if(k >= 30){
		int cur = 1L<<30;
		while(s != 0){
			if(s >= cur){
				s -= cur;
				ans[++res] = cur;
			}
			cur /= 2;
		}
	}
	else{
		ff[0] = 0;
		for(int i = 1; i < k; ++i)
			ff[i] = 0;
		ff[k] = 1;
		for(int i = k + 1; ff[i - 1] <= 1000000000LL; ++i)
			for(int j = 1; j <= k; ++j)
				ff[i] += ff[i - j];
		int i = k + 1;
		while(ff[i] < s)++i;
		while(s != 0){
			if(s >= ff[i]){
				s -= ff[i];
				ans[++res] = ff[i];
			}
			--i;
		}
	}
	ans[++res] = 0;
	printf("%d\n", res);
	for(int i = 1; i <= res; ++i)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}