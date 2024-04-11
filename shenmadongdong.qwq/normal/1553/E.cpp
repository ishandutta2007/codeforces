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
void rd(auto &x){x=0;int f=1;char ch=getchar();while(ch<48||ch>57){if(ch==45)f=-1;ch=getchar();}while(ch>=48&&ch<=57)x=x*10+ch-48,ch=getchar();x*=f;}
ll ksm(ll x,ll y=mod-2,ll m=mod){ll ret=1;while(y){if(y&1)ret=ret*x%m;y>>=1ll;x=x*x%m;}return ret;}
ll qpow(ll x,ll y=2){ll ret=1;while(y>0){if(y&1ll)ret=ret*x;y>>=1ll;x=x*x;}return ret;}
/*
    [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
    [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
    [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
*/
int n,m,p[300010],dis[300010],pos[300010],q[300010];
vector<int> wzak;
bool v[300010];
bool chk(int x)
{
    int tot=0;
	F(i) q[i]=p[(i+x-1)%n+1],v[i]=0;
	F(i) tot+=(q[i]!=i);
	F(i) if (q[i]!=i&&!v[i]) 
    {
        v[i]=1,tot--;
        int j=q[i];
        while(j!=i) v[j]=1,j=q[j];
    }
	return (tot<=m);
}
int main()
{
	DC
    {
        wzak.clear();
        cin>>n>>m;
        F(i) rd(p[i]);
        F(i) dis[i]=i-p[i];
        F(i) if (dis[i]<0) dis[i]+=n;
        F(i) pos[dis[i]]++;
        rep(i,0,n-1) if (n-pos[i]<=m*2&&chk(i)) wzak.push_back(i);
        cout<<wzak.size()<<' ';
        for(int u:wzak) cout<<u<<' ';
        putchar(10);
        rep(i,0,n-1) pos[i]=0;
    }
	return 0;
}