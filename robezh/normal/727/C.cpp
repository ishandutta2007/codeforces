#include<cstdio>
#include<iostream>
#include<map>
using namespace std;

int n;
int num[5005];

int main(){
	int a, b, c, s;
	scanf("%d", &n);
	printf("? 1 2\n"), fflush(stdout), scanf("%d", &a);
	printf("? 1 3\n"), fflush(stdout), scanf("%d", &b);
	printf("? 2 3\n"), fflush(stdout), scanf("%d", &c);
	s = (a + b + c) / 2;
	num[0] = s - c;
	num[1] = s - b;
	num[2] = s - a;
	for(int i = 3; i < n; i++){
		printf("? 1 %d\n", i+1);
		fflush(stdout);
		scanf("%d", &num[i]);
		num[i] -= num[0];
	}
	printf("! ");
	for(int i = 0; i < n; i++){
		printf("%d ", num[i]);
	}
	fflush(stdout);
}