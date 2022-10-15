/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-24 00:23:10
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int a,b,c,n;
int main()
{
    scanf("%d%d%d%d",&a,&b,&c,&n);
    if(a>=n||b>=n||c>=n||a<c||b<c||n-(a+b-c)<1) puts("-1");
    else printf("%d\n",n-(a+b-c));
    return 0;
}