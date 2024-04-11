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
const unsigned mod=998244353;
const unsigned _mod=1e9+7;
const ll infi=0x3f3f3f3f3f3f3f3fll;
const int inf=0x3f3f3f3f;
void rd(auto &wzak){wzak=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch==45)f=-1;ch=getchar();}while(isdigit(ch))wzak=wzak*10+ch-48,ch=getchar();wzak*=f;}
ll ksm(ll wzak,ll y=mod-2,ll m=mod){ll ret=1;while(y){if(y&1)ret=ret*wzak%m;y>>=1;wzak=wzak*wzak%m;}return ret;}
ll qpow(ll wzak,ll y=2){ll ret=1;while(y){if(y&1)ret=ret*wzak;y>>=1;wzak=wzak*wzak;}return ret;}
/*
	[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
	[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
	[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
*/
int n,a[4010];
vector<int> wzak;
int main()
{
	DC
	{
		wzak.clear();
		cin>>n;
		F(i) rd(a[i]);
		bool flag=0;
		F(i) if (i&1^a[i]&1) flag=1;
		if (!flag) for(int i=n;i>1;i-=2) 
		{
		  	int p=1;
		  	rep(j,1,i) if (a[j]==i) {p=j;break;}
		  	wzak.push_back(p);
		  	reverse(a+1,a+p+1);
		  	rep(j,1,i) if (a[j]+1==i) {p=j;break;}
			wzak.push_back(p-1);
			reverse(a+1,a+p);
			wzak.push_back(p+1);
			reverse(a+1,a+p+2);
			wzak.push_back(3);
			reverse(a+1,a+4);
			wzak.push_back(i);
			reverse(a+1,a+i+1);
		}
		if (flag) puts("-1");
		else
		{
			cout<<wzak.size()<<'\n';
			for(int u:wzak) cout<<u<<' ';
			putchar(10);
		}
	}
	return 0;
}