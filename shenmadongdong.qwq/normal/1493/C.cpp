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
#define rd(x) x=read()
using namespace std;
const unsigned mod=998244353;
const unsigned _mod=1e9+7;
const ll infi=0x3f3f3f3f3f3f3fll;
const int inf=0x3f3f3f3f;
ll read(){ll x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
ll ksm(ll x,ll y=mod-2,ll m=mod){ll ret=1;while(y){if(y&1)ret=ret*x%m;y>>=1ll;x=x*x%m;}return ret;}
ll qpow(ll x,ll y){ll ret=1;while(y){if(y&1ll)ret=ret*x;y>>=1ll;x=x*x;}return ret;}
/*
    [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
    [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
    [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
*/
int n,k,a[100010][27],b[100010],t;
string s;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	DC
	{
		bool flag=0;
		cin>>n>>k>>s;
		s=" "+s;
		if (n%k) {cout<<"-1"<<'\n';continue;}
		F(i)
		{
			rep(j,1,26) a[i][j-1]=a[i-1][j-1];
			++a[i][s[i]-97];
		}
		req(i,n,0)
		{
			if (flag==1) break;
			t=0;
			rep(j,1,26) b[j-1]=(k-a[i][j-1]%k)%k,t+=b[j-1];
			if (!t&&i==n)
			{
				F(i) cout<<s[i];
				flag=1;
				cout<<'\n';
				break;
			}
			if (n-i<t) continue;
			rep(c,s[i+1]+1,122)
			{
				if (flag==1) break;
				if (!b[c-97]) b[c-97]=k-1,t+=k-1;
				else --t,--b[c-97];
				if (t>n-i-1) {b[c-97]=0,t-=k-1;continue;}
				while(t+i<=n-2) t+=k,b[0]+=k;
				rep(j,1,i) cout<<s[j];
				cout<<(char)c;
				rep(_,97,122) rep(j,1,b[_-97]) cout<<(char)_;
				cout<<'\n';
				flag=1;
			}
		}
		if (!flag) cout<<"-1"<<'\n';
	}
	return 0;
}