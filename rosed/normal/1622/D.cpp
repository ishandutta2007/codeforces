#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long 
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define eps (1e-8)
	inline int read()
	{
		int x=0;char ch,f=0;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=1,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?-x:x;
	}
	const int N=3e5+10,mod=998244353;
	int n,k,sum;
	char s[N];
	int pre[N];
	int c[5010][5010];
	int f[N];
	inline void main()
	{
		n=read(),k=read();sum=1;
		for(int i=0;i<=n;++i)
		{
			c[i][0]=1;
			for(int j=1;j<=i;++j)
			{
				c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
			}
		}
		cin>>(s+1);
		for(int i=1;i<=n;++i)
		{
			pre[i]=pre[i-1]+(s[i]=='1');
		}
		int t=1;
		for(int i=1;i<=n;++i)
		{
			if(s[i]=='0') continue;
			while(pre[i]-pre[t-1]>k) ++t;
			if(pre[i]-pre[t-1]<k) continue;
			while(s[i+1]=='0'&&i<n) ++i;
			sum=(sum+c[i-t+1][k]-1)%mod;
		//	cout<<sum<<"!!!"<<endl;
			int pos=-1;
			for(int j=t;j<i;++j) if(s[j]=='1')
			{
				if(pre[n]-pre[j]>=k) pos=j+1;
				break;
			//	cout<<j<<' '<<i<<' '<<i-j+1<<' '<<pre[i]-pre[j-1]<<"!!!!!!!!"<<endl; 
			//	sum=(sum-c[i-j+1][pre[i]-pre[j-1]]+1)%mod;
			}
			if(pos==-1) continue;
		//	cout<<pos<<' '<<i<<' '<<i-pos+1<<' '<<pre[i]-pre[pos-1]<<"!!!!"<<endl;
			sum=(sum-c[i-pos+1][pre[i]-pre[pos-1]]+1)%mod;
		//	cout<<t<<' '<<i<<' '<<sum<<"!!"<<endl;
		}
		printf("%lld\n",(sum%mod+mod)%mod);
	}
}
signed main()
{
	red::main();
	return 0;
}
/*
10 7
1001011011
1111
*/