#include<bits/stdc++.h>
#define int long long
#define rd(x) x=read()
using namespace std;

const int N=3e5+5;
const int mod=998244353;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
int ksm(int x,int y){int ret=1;while (y){if (y&1) ret=(ret*x)%mod;x=(x*x)%mod;y>>=1;}return ret;}

int n,k,ans; 
int vis[N];
set<int> S;
vector<int> t;
vector<int> v;
signed main()
{
	int T;cin>>T;
	while (T--)
	{
		ans++;
		rd(n);rd(k);
		v.clear();
		for (int i=(k+1)/2;i<k;i++) v.push_back(i);
		for (int i=k+1;i<=n;i++) v.push_back(i);
		cout<<v.size()<<endl;
		for (int x:v) cout<<x<<" ";cout<<endl;
	}
}