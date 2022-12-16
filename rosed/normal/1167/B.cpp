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
	const int N=3e5+10;
	int num,n; 
	int a[10],b[10],d[10];
	int zy[10010],qwq[10];
	inline int gcd(int a,int b){return b?gcd(b,a%b):a;}
	int c[100];
	inline void main()
	{
		c[4]=c[8]=c[15]=c[16]=c[23]=c[42]=1;
		d[1]=4,d[2]=8,d[3]=15,d[4]=16,d[5]=23,d[6]=42;
		for(int i=1;i<=6;++i)
		{
			for(int j=i+1;j<=6;++j)
			{
				zy[d[i]*d[j]]=(1<<i)|(1<<j);
			}
		}
		for(int i=1;i<=4;++i)
		{
			printf("? %lld %lld\n",i,i+1);
			fflush(stdout);
			qwq[i]=read();
			b[i]=zy[qwq[i]];
		//	b[i]=zy[read()];
		}
		for(int i=1;i<4;++i)
		{
			int tmp=b[i]&b[i+1];
			for(int k=1;k<=6;++k)
			{
				if(tmp&(1<<k)) a[i+1]=d[k];
			}
		}
	//	for(int i=1;i<=6;++i) cout<<a[i]<<"!!"<<endl;
		for(int i=6;i>1;--i)
		{
			if(a[i]) a[i-1]=qwq[i-1]/a[i];
		}
		for(int i=1;i<=5;++i)
			if(a[i]) a[i+1]=qwq[i]/a[i];
		for(int i=1;i<=5;++i) --c[a[i]];
		if(c[4]) a[6]=4;if(c[8]) a[6]=8;if(c[16]) a[6]=16;
		if(c[15]) a[6]=15;if(c[23]) a[6]=23;if(c[42]) a[6]=42;
		putchar('!');
		for(int i=1;i<=6;++i) printf(" %lld",a[i]);
		puts("");
	}
}
signed main()
{
	red::main();
	return 0;
}
/*
345 368 128 32

15 23 16 8 4 42 

*/