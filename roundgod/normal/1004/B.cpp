/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-06 13:42:10
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
int n,m,l,r;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++) scanf("%d%d",&l,&r);
    for(int i=0;i<n;i++)
        printf("%c",(i&1)+'0');
    return 0;
}