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
    const int N=1e5+10;
    int x0,y0,ax,ay,bx,by;
    int stx,sty,n,num;
   	int ret;
   	struct node
   	{
    	int x,y,dis;
   	}a[N];
    int s[N];
    inline int dis(int x,int y,int xx,int yy)
    {
   		return abs(x-xx)+abs(y-yy);
    }
    inline int solve1(int &n,int pos)
   	{
    	int sum=0;
    	while(pos^1)
    	{
    		n-=s[pos]-s[pos-1];
    		if(n<0) return sum;
    		++sum;
    		--pos;
    	}
   		return sum;
    }
    inline int solve2(int &n,int pos)
    {
    	int sum=0;
    	while(pos^num)
    	{
    		n-=s[pos+1]-s[pos];
    		if(n<0) return sum;
    		++sum;
    		++pos;
    	}
    	return sum;
    }
    inline void main()
    {
    	x0=read(),y0=read(),ax=read(),ay=read(),bx=read(),by=read();
    	stx=read(),sty=read(),n=read();
    	a[++num]=(node){x0,y0,dis(stx,sty,x0,y0)};
    	while("haku")
    	{
    		x0=ax*x0+bx,y0=ay*y0+by;
    		if(dis(stx,sty,x0,y0)>n&&x0>stx&&y0>sty) break;
    		if(x0<0||y0<0) break;
    		if(x0>stx+n||y0>sty+n) break;
    		a[++num]=(node){x0,y0,dis(stx,sty,x0,y0)};
    	}
    	for(int i=2;i<=num;++i)
    	{
    		s[i]=s[i-1]+dis(a[i-1].x,a[i-1].y,a[i].x,a[i].y);
		}
    	for(int pos=1;pos<=num;++pos)
    	{
    		if(a[pos].dis>n) continue;
    		int tmp=n-a[pos].dis;
    		int ans=1;
    		ans+=solve1(tmp,pos);
    		solve1(tmp,pos);
   			if(tmp>0) ans+=solve2(tmp,pos);
   			ret=max(ret,ans);
		}
   		cout<<ret<<endl;
   	}
}
signed main()
{
   	red::main();
return 0;
}