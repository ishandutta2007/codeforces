#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
    inline int read()
    {
    	int x=0;char ch,f=1;
    	for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
    	if(ch=='-') f=0,ch=getchar();
    	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();} 
    	return f?x:-x;
    }
    const int N=5e5+10,p=998244353;
    int haku;
    int n,sum,ret,pos;
    int a[N],c[N];
    int st[N],top;
    int s1[N],s2[N];
    inline void main()
    {
    	n=read();
    	for(int i=1;i<=n;++i) a[i]=read();
    	for(int i=1;i<=n;++i)
    	{
    		s1[i]=s1[i-1];
    		while(top&&a[i]<=a[st[top]])
    		{
    			s1[i]-=(st[top]-st[top-1])*a[st[top]];
    			--top;
    		}
    		s1[i]+=(i-st[top])*a[i];
    		st[++top]=i;
    	}
    	st[top=0]=n+1;
    	for(int i=n;i;--i)
    	{
   			s2[i]=s2[i+1];
    		while(top&&a[i]<=a[st[top]])
    		{
    			s2[i]-=(st[top-1]-st[top])*a[st[top]];
    			--top;
    		}
    		s2[i]+=(st[top]-i)*a[i];
    		st[++top]=i;
    	}
    	for(int i=0;i<=n;++i)
    	{
    		if(s1[i]+s2[i+1]>ret)
    		{
    			pos=a[i]>a[i+1]?i:i+1;
    			ret=s1[i]+s2[i+1];
    		}
    	}
    	c[pos]=a[pos];
    	for(int i=pos-1;i;--i) c[i]=min(a[i],c[i+1]);
    	for(int i=pos+1;i<=n;++i) c[i]=min(a[i],c[i-1]);
    	for(int i=1;i<=n;++i) printf("%lld ",c[i]); 
    }
}
signed main()
{
   	red::main();
   	return 0;
}