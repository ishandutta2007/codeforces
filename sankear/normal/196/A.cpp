#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <cstring>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <complex>
#include <bitset>
 
using namespace std;
 
//#define HOME
#define mp make_pair
#define pb push_back
#define next _next 

typedef long long ll;

char s[100100], ans[100100];
int last[30];
int next[100100][30];
 
int main(){
#ifndef HOME
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout); 
#else
	double start = clock();
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%s", s);
	int n = strlen(s);
	for(int i = 0; i < 26; i++){
		last[i] = -1;
	}
	for(int i = n; i >= 0; i--){
		for(int j = 0; j < 26; j++){
			next[i][j] = last[j];
		}
		if(i > 0){
			last[s[i - 1] - 'a'] = i;
		}
	}
	int len = 0, cur = 0;
	while(true){
		bool fl = false;
		for(int i = 25; i >= 0; i--){
			if(next[cur][i] != -1){
				ans[len++] = 'a' + i;
				cur = next[cur][i];
				fl = true;
				break;
			}
		}
		if(!fl){
			break;
		}
	}
	ans[len] = 0;
	printf("%s\n", ans);
#ifdef HOME
	printf("time = %.18lf\n", (clock() - start) / CLOCKS_PER_SEC);
#endif
	return 0;
}