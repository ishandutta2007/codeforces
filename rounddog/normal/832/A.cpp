#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<iostream>
#include<algorithm>
#define maxn 10020
#define mt 120

using namespace std;

int main()
{ 
    long long int n,k;
    scanf("%I64d%I64d",&n,&k);
    if ((n/k)%2) printf("YES\n"); else printf("NO\n");
    return 0;
}