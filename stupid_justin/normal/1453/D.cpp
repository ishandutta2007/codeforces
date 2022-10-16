#include<bits/stdc++.h>
#define int long long
#define rd(x) x=read()
using namespace std;
const int N=2e6+5;
const int M=5005;
const int mod=998244353;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
int ksm(int x,int y){int ret=1;while (y){if (y&1) ret=(ret*x)%mod;x=(x*x)%mod;y>>=1;}return ret;}
 
int n;
int a[N];

signed main()
{
	int T;
	cin>>T;
	while (T--)
	{
		rd(n);
		if (n%2==1) 
		{
			cout<<"-1\n";
			continue;
		}
		n/=2;
		int cnt=0;
		while (n)
		{
			int i=0,tmp=0;
			while (tmp+(1LL<<i)<=n) tmp+=(1LL<<i),i++;
			a[++cnt]=1;for (int j=1;j<i;j++) a[++cnt]=0;
			n-=tmp;
		}
		cout<<cnt<<"\n";
		for (int i=1;i<=cnt;i++) cout<<a[i]<<" ";
		cout<<"\n";
	}
}