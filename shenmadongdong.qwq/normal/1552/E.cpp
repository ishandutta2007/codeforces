#include<bits/stdc++.h> 
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,mmx,avx,avx2")
#pragma GCC optimize("unroll-loops")
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define req(i,a,b) for(int i=(a);i>=(b);--i)
#define rep_(i,a,b) for(int i=(a);i<(b).size();++i)
#define F(a) rep(a,1,n)
#define M(a,b) memset(a,b,sizeof a)
#define DC int T;cin>>T;while(T--)
#define ll long long
#define Z(a,b) sort(a+1,a+b+1)
using namespace std;
const unsigned _mod=998244353;
const unsigned mod=1e9+7;
const ll infi=0x3f3f3f3f3f3f3fll;
const int inf=0x3f3f3f3f;
void rd(int &x){x=0;int f=1;char ch=getchar();while(ch<48||ch>57){if(ch==45)f=-1;ch=getchar();}while(ch>=48&&ch<=57)x=x*10+ch-48,ch=getchar();x*=f;}
ll ksm(ll x,ll y=mod-2,ll m=mod){ll ret=1;while(y){if(y&1)ret=ret*x%m;y>>=1ll;x=x*x%m;}return ret;}
ll qpow(ll x,ll y=2){ll ret=1;while(y>0){if(y&1ll)ret=ret*x;y>>=1ll;x=x*x;}return ret;}
/*
    [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
    [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
    [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
*/
int n,m,k,a[100010],ansa[100010],ansb[100010],b[100010],lst[100010],nxt[100010],d[100010],e[100010];
int main()
{
	{
		cin>>n>>k;
		rep(i,1,n*k) rd(a[i]);
		rep(i,1,n*k)
		{
			nxt[lst[a[i]]]=i;
			lst[a[i]]=i;
		}
		rep(_,1,(n+k-2)/(k-1))
		{
			m=0;
			int l=_*k-_-k+2,r=min(_*k-_,n);
			rep(i,l,r) d[i]=m;
			int pos=0;
			rep(i,1,n*k) if (a[i]<=r&&a[i]>=l) b[++m]=i;
			rep(i,1,r-l+1)
			{
				int mnn=n*k+1,id;
				rep(j,l,r) d[j]=0;
				rep(j,pos+1,m) if (!((d[a[b[j]]]>0)|(e[a[b[j]]]>0))) d[a[b[j]]]=nxt[b[j]];
				rep(j,l,r) if (!e[j]&&d[j]<mnn) id=j,mnn=d[id];
				int pos2=0;e[id]=1;
				rep(j,pos+1,m) if (a[b[j]]==id) {pos2=b[j];break;}
				ansb[id]=mnn,ansa[id]=pos2;
				int wzak=0,wz=0;
				rep(j,pos+1,m)
				{
					if (a[b[j]]==id) wzak++; 
					if (wzak==2) {wz=j;break;}
				}
				pos=wz;
			}
		}
		F(i) cout<<ansa[i]<<' '<<ansb[i]<<'\n';
	}
	return 0;
}