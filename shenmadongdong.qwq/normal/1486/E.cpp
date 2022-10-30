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
#define Z(a) sort(a+1,a+n+1)
using namespace std;
const unsigned _mod=998244353;
const unsigned mod=1e9+7;
const ll infi=0x3f3f3f3f3f3f3fll;
const int inf=0x3f3f3f3f;
void rd(ll &x){x=0;int f=1;char ch=getchar();while(ch<48||ch>57){if(ch==45)f=-1;ch=getchar();}while(ch>=48&&ch<=57)x=x*10+ch-48,ch=getchar();x*=f;}
ll ksm(ll x,ll y=mod-2,ll m=mod){ll ret=1;while(y){if(y&1)ret=ret*x%m;y>>=1ll;x=x*x%m;}return ret;}
ll qpow(ll x,ll y){ll ret=1;while(y){if(y&1ll)ret=ret*x;y>>=1ll;x=x*x;}return ret;}
/*
    [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
    [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
    [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
*/
ll n,m,d[100010][60],u,v,w;
struct Edge{ 
	ll to,w; 
};
vector<Edge> vec[100010];
char vis[100010][60];
struct jyztxdy 
{
  	ll a,b,c;
  	inline bool operator <(const jyztxdy& rhs) const {
    	return c>rhs.c;
  	}
};priority_queue<jyztxdy> q;
int main() 
{
  	cin>>n>>m;
  	rep(i,1,m) rd(u),rd(v),rd(w),vec[u].push_back(Edge{v,w}),vec[v].push_back(Edge{u,w});
  	M(d,0x3f);d[1][0]=0;
	q.push(jyztxdy{1,0,0});
  	while(q.size()) 
	{
    	jyztxdy x=q.top();q.pop();
		if (!vis[x.a][x.b])
		{
			vis[x.a][x.b]=1;
    		if (x.b) {for(auto y:vec[x.a]) if (d[y.to][0]>x.c+qpow(x.b+y.w,2)) d[y.to][0]=x.c+qpow(x.b+y.w,2),q.push(jyztxdy{y.to,0,d[y.to][0]});}
    		else {for(auto y:vec[x.a]) if (d[y.to][y.w]>x.c) d[y.to][y.w]=x.c,q.push(jyztxdy{y.to,y.w,x.c});}
		}
  	}
  	F(i) cout<<(d[i][0]>=infi?-1:d[i][0])<<' ';
  	puts("");
  	return 0;
}