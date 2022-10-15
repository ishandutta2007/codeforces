#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,x,a[MAXN],b[MAXN];
int al[MAXN],ar[MAXN],bl[MAXN],br[MAXN],na[MAXN],nb[MAXN];
P st[MAXN];
//a+b<=x
//na+b>x
//a+nb>x
//x-na<b<=x-a
//nb>x-a
int bit[MAXN+1];
int sum(int i)
{
    int s=0;
    while(i>0)
    {
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(int i,int x)
{
    while(i<=200000)
    {
        bit[i]+=x;
        i+=i&-i;
    }
}
void compute(int n,int a[],int l[],int r[],int na[])
{
    for(int i=1;i<=n;i++) na[i]=x;
    int t=0;
    st[t++]=P(0,0);
    for(int i=1;i<=n;i++)
	{
		while(a[st[t-1].F]>=a[i]) 
        {
            assert(t!=1);
            st[t-2].S=max(st[t-2].S,st[t-1].S);
            t--;
        }
		l[i]=t==0?0:st[t-1].F;
        if(t!=1) na[i]=min(na[i],max(a[i],st[t-1].S));
		st[t++]=P(i,a[i]);
	}
	t=0; st[t++]=P(0,0);
	for(int i=n;i>=1;i--)
	{
		while(a[st[t-1].F]>a[i]) 
        {
            assert(t!=1);
            st[t-2].S=max(st[t-2].S,st[t-1].S);
            t--;
        }
		r[i]=t==0?n+1:st[t-1].F;
        if(t!=1) na[i]=min(na[i],max(a[i],st[t-1].S));
		st[t++]=P(i,a[i]);
	}
}
int main()
{
    scanf("%d%d%d",&n,&m,&x);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=m;i++) scanf("%d",&b[i]);
    compute(n,a,al,ar,na); compute(m,b,bl,br,nb);
    vector<P> va,vb;
    for(int i=1;i<=n;i++) va.push_back(P(a[i],na[i]));
    for(int i=1;i<=m;i++) vb.push_back(P(nb[i],b[i]));
    sort(va.begin(),va.end()); sort(vb.begin(),vb.end());
    int now=m-1;
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        while(now>=0&&vb[now].F>x-va[i].F) add(vb[now].S,1),now--;
        ans+=sum(x-va[i].F)-sum(x-va[i].S);
    }
    printf("%lld\n",ans);
    return 0;
}