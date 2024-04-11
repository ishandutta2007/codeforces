#include<bits/stdc++.h>
#define int long long
#define rd(x) x=read()
using namespace std;
const int N=1e6+5;
const int M=5005;
const int mod=998244353;
const int inf=0x3f3f3f3f3f3f3f;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
int ksm(int x,int y){int ret=1;while (y){if (y&1) ret=(ret*x)%mod;x=(x*x)%mod;y>>=1;}return ret;}
int p[N],v[N],cnt;
void init()
{
	v[1]=1;
	for (int i=2;i<N;i++)
	{
		if (!v[i]) p[++cnt]=i;
		for (int j=1;j<=cnt && p[j]*i<N;j++)
		{
			v[p[j]*i]=1;
			if (i%p[j]==0) break;
		}
	}
}
int n,d,a,b;
map<int,int> Map[N];
signed main()
{
	int T;
	init();
	cin>>T;
	while(T--)
	{
		rd(d);
		a=d+1;while (v[a]==1) a++;
		b=a+d;while (v[b]==1) b++;
		cout<<min(a*b,a*a*a)<<endl;
	}
}