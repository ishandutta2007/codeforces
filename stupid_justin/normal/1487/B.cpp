#include<bits/stdc++.h>
#define int long long
#define rd(x) x=read()
using namespace std;
const int N=2e6+5;
const int M=5005;
const int mod=998244353;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}

int a[N];
int n,k,ans;
signed main()
{
	int T;
	cin>>T;
	while (T--)
	{
		rd(n);rd(k);
		if (n%2==1) k+=(k-1)/(n/2);
		ans=k%n;if (ans==0) ans=n;
		cout<<ans<<endl;	

	}
}