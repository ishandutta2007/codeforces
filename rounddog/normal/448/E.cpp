#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define maxn 100020

using namespace std;
typedef __int64 ll;

int cnt,t,t2;
ll n,m,ans[maxn],p[maxn],q[maxn];

void dfs(int a,int k)
{
	if (cnt==100000) return;
	if (k==m||a==1){
	    cnt++;
	    printf("%I64d ",p[a]);
	    return;
    }
    for (int i=1;i<=a;i++)
        if (p[a]%p[i]==0) dfs(i,k+1);
}

int main()
{
	scanf("%I64d%I64d",&n,&m);
	if (m>100001) m=100001;
	if (n==1) {printf("1\n"); return 0;}
	cnt=0;t=0;
    for (int i=1;(ll)i*i<=n;i++)
    {
        if (n%i==0){
            t+=1;
            if (t<maxn) p[t]=i,q[t]=n/i;
        }
    }
    if (p[t]==q[t]) t2=t-1; else t2=t;
    while (t2&&t+1<maxn)
        p[++t]=q[t2--];
	dfs(t,0);
    return 0;
}