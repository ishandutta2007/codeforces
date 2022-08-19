#include <bits/stdc++.h>
#define maxn 100005
#define ll long long
#define mod 998244353
using namespace std;
int b, k;
int a[maxn];
int main()
{
	scanf("%d%d", &b, &k);
	int ns = 0, mt = 1;
	for(int i = 0; i < k; i++)
		scanf("%d", &a[i]), 
		ns = ns * b + a[i], 
		ns %= 2;
	if(ns == 0) printf("even");
	else printf("odd");
	return 0;
}