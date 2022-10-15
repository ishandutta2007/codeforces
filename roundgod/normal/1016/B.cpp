/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-03 22:50:43
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
int n,m,q;
string s,t;
int a[MAXN];
int main()
{
    scanf("%d%d%d",&n,&m,&q);
    cin>>s;cin>>t;
    for(int i=0;i+m<=n;i++)
        if(s.substr(i,m)==t) a[i+1]=1; else a[i+1]=0;
    //for(int i=1;i<=14;i++) printf("%d ",a[i]);
    for(int i=1;i<=n-m+1;i++) a[i]=a[i]+a[i-1];
    for(int i=0;i<q;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        r=r-m+1;
        if(r<l||n<m) puts("0"); else printf("%d\n",a[r]-a[l-1]);
    }
    return 0;
}