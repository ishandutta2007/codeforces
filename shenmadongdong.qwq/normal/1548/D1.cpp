#include <bits/stdc++.h>
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
int t[16][3],p[3];
ll n,a[11],b[6010][2],q[3],s;
inline ll f(ll p){return p%4==0?0:2;}
int main()
{
    rep(i,7,15) t[i][0]++;
    rep(i,12,15) t[i][0]++;
    rep(i,15,15) t[i][0]++;
    rep(i,4,15) t[i][1]++;
    rep(i,10,15) t[i][1]++;
    rep(i,14,15) t[i][1]++;
    t[5][1]++,t[6][1]++,t[11][1]++,t[6][1]++;
    rep(i,1,9) t[i][2]=i%3;
    rep(i,1,9) if (t[i][2]==0) t[i][2]=3;
    rep(i,10,15) t[i][2]=3;
    t[10][2]--,t[12][2]--;
	cin>>n;
	F(i) rd(b[i][0]),rd(b[i][1]),a[f(b[i][0])+f(b[i][1])/2]++;
	rep(i,0,15)
    {
        p[0]=t[i][0],p[1]=t[i][1],p[2]=t[i][2];
        q[0]=a[p[0]],q[1]=a[p[1]],q[2]=a[p[2]];
		if (p[0]==p[1]&&p[1]==p[2]) s+=q[0]*(q[0]-1)*(q[0]-2)/6;
		else if (p[0]==p[1]) s+=q[2]*q[0]*(q[0]-1)/2;
		else if (p[1]==p[2]) s+=q[0]*q[1]*(q[1]-1)/2;
		else s+=q[0]*q[1]*q[2];
	}
	cout<<s<<'\n';
    return 0;
}