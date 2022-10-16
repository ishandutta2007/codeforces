#include<bits/stdc++.h>
#define int long long
#define rd(x) x=read()
using namespace std;
const int N=2e2+5;
const int M=5005;
const int mod=998244353;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
 
int ans[N][N];
int n,k;
int f(int x){x=(x%n+n)%n;if (x==0) x=n;return x;}
signed main()
{
	int T;
	cin>>T;
	while (T--)
	{
		rd(n);
		if (n<5){cout<<"0"<<"\n";continue;}
		int k=sqrt(n*2-1);k=(k-1)/2;
		cout<<k<<'\n';
	}
}