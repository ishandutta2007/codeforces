#include<bits/stdc++.h>
#define int long long
#define ls (rt<<1)
#define rs (rt<<1|1)
#define pii pair<int,int>
#define fi first
#define se second
#define rd(x) x=read()
#define endl '\n'
using namespace std;

const int N=2e5+5;
const int mod=1e9+7;
const int inf=3e18;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}

int n,k,ans;
int a[N];
string s;
signed main()
{
	int T;cin>>T;while (T--)
	{
		bool flag=0;
		cin>>s;n=s.length();s=" "+s;
		for (int i=0;i<=n;i++)
		{
			if (i>0 && i<n && s[i]==49 && s[i+1]==48) continue;
			bool f1=1;
			for (int j=1;j<i;j++) if (s[j]!=48 && s[j+1]!=48) f1=0;
			for (int j=i+1;j<n;j++) if (s[j]!=49 && s[j+1]!=49) f1=0;
			if (f1) flag=1;
		}
		if (flag)puts("YES");else puts("NO");
	}
}