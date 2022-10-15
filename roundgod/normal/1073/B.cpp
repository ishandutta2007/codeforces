/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-25 22:38:35
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN],b[MAXN],pos[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {scanf("%d",&a[i]); pos[a[i]]=i;}
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    int cur=0;
    for(int i=1;i<=n;i++)
    {
        printf("%d ",max(0,pos[b[i]]-cur));
        cur=max(cur,pos[b[i]]);
    }
    return 0;
}