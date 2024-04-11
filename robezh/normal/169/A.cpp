#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int n,a,b;
int num[2005];


int main(){
	scanf("%d%d%d", &n, &a, &b);
	for(int i = 0; i < n; i++) scanf("%d", &num[i]);
	sort(num, num + n);
	cout << num[b] - num[b-1];
}