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
int b[N];
signed main()
{
	rd(n);
	for (int i=1;i<=n;i++) rd(a[i]);
	if (n==1)
	{
		puts("1 1");puts("0");puts("1 1");puts("0");puts("1 1");
		cout<<-a[n]<<endl;
	}
	else
	{
		cout<<"1 "<<n-1<<endl;
		for (int i=1;i<=n-1;i++)
		{
			//n
			int x=a[i]%n;if (x<0) x+=n;
			int y=x*(n-1);
			printf("%lld ",y);
			a[i]+=y;
		}cout<<endl;
		cout<<"1 "<<n<<endl;
		for (int i=1;i<=n-1;i++)
		{
			printf("%lld ",0LL-a[i]);
		}
		cout<<0<<endl;
		cout<<n<<" "<<n<<endl;
		printf("%lld",0LL-a[n]);
	}
	

}