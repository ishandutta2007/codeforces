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

#define maxn 55

using namespace std;

bool ok[maxn][maxn][maxn][maxn];
bool f[maxn][maxn][maxn][maxn];
int stack[maxn];
int n;
int decode[256];

inline bool proof(int a, int b){
	return(a % 13 == b % 13 || a / 13 == b / 13);
}

bool can(int len, int a, int b, int c){
	if(f[len][a][b][c])return(ok[len][a][b][c]);
	f[len][a][b][c] = true;
	if(len <= 3){
		if(len == 3){
			if(proof(c, b))ok[len][a][b][c] = can(len - 1, a, c, 0);
		}
		if(len == 2)ok[len][a][b][c] = proof(b, a);
		if(len == 1)ok[len][a][b][c] = true;
	}
	else{
		if(proof(c, b))
			ok[len][a][b][c] = ok[len][a][b][c] || can(len - 1, stack[len - 3], a, c);
		if(proof(c, stack[len - 3]))
			ok[len][a][b][c] = ok[len][a][b][c] || can(len - 1, c, a, b);
	}
	return(ok[len][a][b][c]);
}

int input_data(){
	int ii = 0;
	for(char c = '2'; c <= '9'; ++c)
		decode[c] = ii++;
	decode['T'] = 8;
	decode['J'] = 9;
	decode['Q'] = 10;
	decode['K'] = 11;
	decode['A'] = 12;
	decode['S'] = 0;
	decode['D'] = 1;
	decode['H'] = 2;
	decode['C'] = 3;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		char up, down;
		scanf(" %c %c", &up, &down);
		stack[i] = decode[down] * 13 + decode[up];
	}
	return 0;
}

int main(){
	input_data();
	if(n == 1){
		printf("YES\n");
		return 0;
	}
	if(n == 2){
		if(proof(stack[1], stack[2]))
			printf("YES\n");
		else
			printf("NO\n");
		return 0;
	}
	bool res = can(n, stack[n - 2], stack[n - 1], stack[n]);
	if(res)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}