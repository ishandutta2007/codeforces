/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-06 13:52:31
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,cnt[MAXN],a[MAXN];
int main()
{
    scanf("%d",&t);
    int x,tot;
    tot=0;
    for(int i=0;i<t;i++)
    {
        scanf("%d",&x);
        cnt[x]++;
        tot=max(tot,x);
    }
    int id=1;
    for(int i=1;i<=tot;i++)
        if(cnt[i]!=4*i) {id=i;break;}
    for(int i=1;i*i<=t;i++)
    {
        if(t%i!=0) continue;
        int n=i,m=t/i;
        int x=id,y=n+m-tot-id;
        if(x>0&&y>0&&x<=n&&y<=m)
        {
            //printf("%d %d %d %d\n",n,m,x,y);
            memset(a,0,sizeof(a));
            for(int j=1;j<=n;j++)
                for(int k=1;k<=m;k++)
                    a[max(j-x,x-j)+max(k-y,y-k)]++;
            bool flag=true;
            for(int j=0;j<=tot;j++)
                if(a[j]!=cnt[j]) {flag=false;break;}
            if(flag)
            {
                printf("%d %d\n%d %d\n",n,m,x,y);
                return 0;
            }
        }
        n=t/i,m=i;x=id,y=n+m-tot-id;
        if(x>0&&y>0&&x<=n&&y<=m)
        {
            //printf("%d %d %d %d\n",n,m,x,y);
            memset(a,0,sizeof(a));
            for(int j=1;j<=n;j++)
                for(int k=1;k<=m;k++)
                    a[max(j-x,x-j)+max(k-y,y-k)]++;
            bool flag=true;
            for(int j=0;j<=tot;j++)
                if(a[j]!=cnt[j]) {flag=false;break;}
            if(flag)
            {
                printf("%d %d\n%d %d\n",n,m,x,y);
                return 0;
            }
        }
    }
    puts("-1");
    return 0;
}