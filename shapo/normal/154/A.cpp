#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <ctype.h>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <functional>

#define maxlen 100500
#define maxk 256

using namespace std;

char s[maxlen], rev[maxlen];
int bad[maxk][maxk];
int num[maxk];
int nn, cur[maxlen];

int add(const int &x, int &y){
	++y; cur[y] = x; return 0;
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	scanf(" %s", s);
	int k;
	scanf("%d", &k);
	for(int i = 1; i <= k; ++i){
		char x, y;
		scanf(" %c%c", &x, &y);
		bad[int(x)][int(y)] = bad[int(y)][int(x)] = 1;
	}
	
	int len = strlen(s), res = 0;
	int l, a, b, i = 0;
	while(i < len){
		l = i; a = b = 0;
		while(i < len && (s[i] == s[l] || bad[int(s[i])][int(s[l])])){
			if(s[i] == s[l])++a;else ++b;
			++i;
		}
		if(a < b)res += a;else res += b;
	}
	
	printf("%d\n", res);
	return 0;
}