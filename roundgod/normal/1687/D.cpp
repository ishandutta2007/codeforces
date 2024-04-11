#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 4500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int pre[MAXN],suf[MAXN],sum[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        pre[a[i]]=a[i];  suf[a[i]]=a[i]; sum[a[i]]++;
    }
    pre[0]=0; 
    for(int i=1;i<=4500000;i++)
    {
        if(!pre[i]) pre[i]=pre[i-1];
        sum[i]+=sum[i-1];
    }
    for(int i=4500000;i>=1;i--) if(!suf[i]) suf[i]=suf[i+1];
    for(int i=1;i<=2000000;i++)
    {
        if(1LL*i*i+i<a[1]) continue; 
        int last=pre[a[1]+i];
        ll l=max(0LL,a[1]-1LL*i*i),r=i-(last-a[1]);
        //printf("i=%d last=%d l=%lld r=%lld\n",i,last,l,r);
        for(int j=1;;j++)
        {
            ll nl=1LL*(i+j)*(i+j)-1LL*i*i-i+a[1],nr=1LL*(i+j)*(i+j)+(i+j)-1LL*i*i+a[1];
            ll lastr=1LL*(i+j-1)*(i+j-1)+(i+j-1)-1LL*i*i+a[1];
            //printf("nl=%lld nr=%lld lastr=%lld\n",nl,nr,lastr);
            if(nl>lastr+1&&sum[nl-1]!=sum[lastr]) {l=1; r=0; break;}
            if(nl>a[n]) break;
            if(!suf[nl]||suf[nl]>nr) continue;
            int fst=suf[nl],last=pre[nr];
            l=max(l,nl+i-fst); r=min(r,nr-last);
        }
        //printf("i=%d l=%lld r=%lld\n",i,l,r);
        if(l<=r) {printf("%lld\n",1LL*i*i+l-a[1]); return 0;}
    }
    assert(0);
    return 0;
}