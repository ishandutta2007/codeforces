#include<bits/stdc++.h>
#define int long long
#define rd(x) x=read()
using namespace std;
const int N=2e6+5;
const int M=5005;
const int mod=998244353;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}

int a[N];
int n,d,Min,se,Max;
signed main()
{
	int T;
	cin>>T;
	while (T--)
	{
		rd(n);rd(d);Min=1000,se=1000,Max=-1000;
		for (int i=1;i<=n;i++)
		{
			int a;rd(a);
			if (a<Min) 
				se=Min,Min=a;
			else if (a<se) se=a;
			Max=max(a,Max);
		}
		//printf("Min=%lld,se=%lld,Max=%lld\n",Min,se,Max);
		if (Max<=d || Min+se<=d) puts("YES");
		else puts("NO");
	}
}