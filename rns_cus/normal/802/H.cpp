#include<bits/stdc++.h>
using namespace std;

#define N 3020

int cnt;
char s[N], t[N];
int a[30], x;

int main(){
	scanf("%d", &x);
	for(int i = 0; i < 13; i ++) {
		a[i] = x % 3;
		x /= 3;
	}
	int tmp = 1;
	for(int i = 0; i < 12; i ++) s[cnt ++] = 'a' + i;
	for(int i = 0; i <= 12; i ++){
		for(int j = 0; j < a[i]; j ++) s[cnt ++] = 'a' + 12;
		for(int j = 11; j >= i; j --){
			s[cnt ++] = 'a' + j;
			s[cnt ++] = 'a' + j;
		}
	}
	puts(s);
	for(int i = 0; i <= 12; i ++) printf("%c", 'a' + i); puts("");
}