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

#define maxn 150
#define maxl 101
#define maxs 2501

using namespace std;

const long long pp = 1000000007;
char s[maxn];
int t;
long long res[maxs][maxl];
int lres[100000];

int init(){
	for(int i = 0; i < maxs; ++i)
		for(int j = 0; j < maxl; ++j)
			res[i][j] = 0;
	res[0][0] = 1;
	for(int i = 1; i < maxl; ++i)
		for(int j = 0; j < maxs; ++j)
			for(int k = 0; k <= 25; ++k)
				if(j - k >= 0)res[j][i] = (res[j][i] + res[j - k][i - 1]) % pp;
	return 0;
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	scanf("%d", &t);
	init();
	for(int k = 1; k <= t; ++k){
		scanf(" %s", s);
		int len = strlen(s), sum = 0;
		
		for(int i = 0; i < len; ++i)sum += int(s[i] - 'a');
		lres[k] = (res[sum][len] + pp - 1) % pp;
	}
	
	for(int i = 1; i <= t; ++i)printf("%d\n", lres[i]);
	
	return 0;
}