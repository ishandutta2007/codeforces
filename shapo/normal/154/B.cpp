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

#define maxn 100500

using namespace std;

int n, m;
int num[maxn];
int sw[maxn];

int bad(const int &x){
	int i = 2;
	if(num[x])return num[x];
	while(i * i <= x){
		if(x % i == 0){
			if(num[i])return num[i];
			if(num[x / i])return num[x / i];
		}
		++i;
	}
	return 0;
}

int switch_on(const int &x){
	int i = 2;
	num[x] = x;
	while(i * i <= x){
		if(x % i == 0)num[i] = num[x / i] = x;
		++i;
	}
	sw[x] = 1;
	printf("Success\n");
	return 0;
}

int switch_off(const int &x){
	int i = 2;
	num[x] = 0;
	while(i * i <= x){
		if(x % i == 0)num[i] = num[x / i] = 0;
		++i;
	}
	sw[x] = 0;
	printf("Success\n");
	return 0;
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	scanf("%d %d", &n, &m);
	
	for(int i = 1; i <= m; ++i){
		char a;
		int x;
		scanf(" %c%d", &a, &x);
		if(a == '+'){
			if(sw[x])printf("Already on\n");
			else{
				int xx = bad(x);
				if(xx == 0)switch_on(x);
				else printf("Conflict with %d\n", xx);
			}
		}
		else{
			if(!sw[x])printf("Already off\n");
			else switch_off(x);
		}
	}
	
	return 0;
}