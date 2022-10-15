#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 250005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN],nxtgt[MAXN],nxtsm[MAXN];
int st[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int tot=0;
        for(int i=n;i>=1;i--)
        {
            while(tot>0&&a[st[tot-1]]>=a[i]) tot--;
            nxtsm[i]=(tot==0?n+1:st[tot-1]);
            st[tot++]=i;
        }
        tot=0;
        for(int i=n;i>=1;i--)
        {
            while(tot>0&&a[st[tot-1]]<=a[i]) tot--;
            nxtgt[i]=(tot==0?n+1:st[tot-1]);
            st[tot++]=i;
        }
        int ans=0,now=1;
        while(now!=n)
        {
            if(now==n-1) {ans++; break;}
            if(a[now+1]>a[now])
            {
                int nxt=now+1;
                while(nxtgt[nxt]<nxtsm[now]) nxt=nxtgt[nxt];
                now=nxt; ans++;
            }
            else
            {
                int nxt=now+1;
                while(nxtsm[nxt]<nxtgt[now]) nxt=nxtsm[nxt];
                now=nxt; ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}