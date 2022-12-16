#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define eps (1e-6)
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1) 
	inline int read()
	{
		int x=0;char ch,f=1;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=0,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?x:-x;
	}
	const int N=1e6+10;
	int n,x;
	int sum[N];
	int st[N],top;
	double ans[N];
	inline void main()
	{
		n=read();
		for(int i=1;i<=n;++i)
		{
			x=read();
			sum[i]=sum[i-1]+x;
			int pre=i,tmp=x;
			while(top&&(sum[pre-1]-sum[st[top]-1])*(i-pre+1)>=tmp*(pre-st[top]))
			{
				tmp+=sum[pre-1]-sum[st[top]-1];
				pre=st[top];
				--top;
			}
			st[++top]=pre;
		}
		int cur=n;
		while(top)
		{
			int t=cur;
			while(cur>=st[top]) ans[cur--]=(double(sum[t]-sum[st[top]-1]))/(t-st[top]+1);
			--top;
		}
		for(int i=1;i<=n;++i) printf("%.9f\n",ans[i]);
	}
}
signed main()
{

	red::main();
	return 0;
}