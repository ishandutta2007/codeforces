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

#define maxn 100500

using namespace std;

int pos[maxn], neg[maxn], num[maxn], nt[maxn];
int n, m, com = 0, ct = 0, cl = 0, nmm = 0;
bool ok[maxn];
int p[maxn];

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i){
		char a; int b;
		scanf(" %c%d", &a, &b);
		if(a == '-')++neg[b]; else ++pos[b];
		ok[i] = (a == '+');
		p[i] = b;
	}
	for(int i = 1; i <= n; ++i){
		ct += pos[i];
		cl += neg[i];
	}
	
	for(int i = 1; i <= n; ++i){
		num[i] = pos[i] + (cl - neg[i]);
		if(num[i] == m){++nmm; nt[i] = 1;}
	}
	
	for(int i = 1; i <= n; ++i)
		if(ok[i]){
			if(nmm - nt[p[i]] == 0)printf("Truth\n");
			else{
				if(nt[p[i]] == 0)printf("Lie\n");else printf("Not defined\n");
			}
		}
		else{
			if(nt[p[i]] == 0)printf("Truth\n");
			else{
				if(nmm - nt[p[i]] == 0)printf("Lie\n"); else printf("Not defined\n");
			}
		}
	
	return 0;
}