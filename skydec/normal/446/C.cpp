#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<iostream>
#include<algorithm>
using namespace std;
namespace fastIO{
	#define BUF_SIZE 100000
	//fread->read
	bool IOerror=0;
	inline char nc(){
		static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE;
		if (p1==pend){
			p1=buf; pend=buf+fread(buf,1,BUF_SIZE,stdin);
			if (pend==p1){IOerror=1;return -1;}
			//{printf("IO error!\n");system("pause");for (;;);exit(0);}
		}
		return *p1++;
	}
	inline bool blank(char ch){return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';}
	inline void read(int &x){
		bool sign=0; char ch=nc(); x=0;
		for (;blank(ch);ch=nc());
		if (IOerror)return;
		if (ch=='-')sign=1,ch=nc();
		for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
		if (sign)x=-x;
	}
	inline void read(double &x){
		bool sign=0; char ch=nc(); x=0;
		for (;blank(ch);ch=nc());
		if (IOerror)return;
		if (ch=='-')sign=1,ch=nc();
		for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
		if (ch=='.'){
			double tmp=1; ch=nc();
			for (;ch>='0'&&ch<='9';ch=nc())tmp/=10.0,x+=tmp*(ch-'0');
		}
		if (sign)x=-x;
	}
	inline void read(char *s){
		char ch=nc();
		for (;blank(ch);ch=nc());
		if (IOerror)return;
		for (;!blank(ch)&&!IOerror;ch=nc())*s++=ch;
		*s=0;
	}
	//getchar->read
	inline void read1(int &x){
		char ch;int bo=0;x=0;
		for (ch=getchar();ch<'0'||ch>'9';ch=getchar())if (ch=='-')bo=1;
		for (;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar());
		if (bo)x=-x;
	}
	inline void read1(double &x){
		char ch;int bo=0;x=0;
		for (ch=getchar();ch<'0'||ch>'9';ch=getchar())if (ch=='-')bo=1;
		for (;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar());
		if (ch=='.'){
			double tmp=1;
			for (ch=getchar();ch>='0'&&ch<='9';tmp/=10.0,x+=tmp*(ch-'0'),ch=getchar());
		}
		if (bo)x=-x;
	}
	void read1(char *s){
		char ch=getchar();
		for (;blank(ch);ch=getchar());
		for (;!blank(ch);ch=getchar())*s++=ch;
		*s=0;
	}
	//scanf->read
	void read2(int &x){scanf("%d",&x);}
	void read2(double &x){scanf("%lf",&x);}
	void read2(char *s){scanf("%s",s);}
	//fwrite->write
	struct Ostream_fwrite{
		char *buf,*p1,*pend;
		Ostream_fwrite(){buf=new char[BUF_SIZE];p1=buf;pend=buf+BUF_SIZE;}
		void out(char ch){
			if (p1==pend){
				fwrite(buf,1,BUF_SIZE,stdout);p1=buf;
			}
			*p1++=ch;
		}
		void print(int x){
			static char s[15],*s1;s1=s;
			if (!x)*s1++='0';if (x<0)*s1++='-',x=-x;
			while(x)*s1++=x%10+'0',x/=10;
			while(s1--!=s)out(*s1); out('\n');
		}
		void print(char *s){
			while (*s)out(*s++);out('\n');
		}
		void flush(){
			if (p1!=buf){fwrite(buf,1,p1-buf,stdout);p1=buf;}
		}
		~Ostream_fwrite(){flush();}
	}Ostream;
	inline void print(int x){Ostream.print(x);}
	inline void print(char *s){Ostream.print(s);}
	inline void flush(){Ostream.flush();}
	//puts->write
	char Out[BUF_SIZE],*o=Out;
	inline void print1(int x){
		static char buf[15];
		char *p1=buf;if (!x)*p1++='0';if (x<0)*p1++='-',x=-x;
		while(x)*p1++=x%10+'0',x/=10;
		while(p1--!=buf)*o++=*p1; *o++='\n';
	}
	inline void print1(char *s){
		while (*s)*o++=*s++; *o++='\n';
	}
	inline void flush1(){if (o!=Out)*--o=0;puts(Out);}
	#undef BUF_SIZE
};
using namespace fastIO;
#define MAXN 310000
#define jsb 1000000009
using namespace std;
struct yd
{
       int v[2][2];
       inline yd operator *(const yd &b)
       {
                   yd c={};
                   c.v[0][0]=v[0][1]*1ll*b.v[1][0]%jsb;
                   c.v[0][0]=(c.v[0][0]+v[0][0]*1ll*b.v[0][0])%jsb;
                   
                   c.v[0][1]=v[0][1]*1ll*b.v[1][1]%jsb;
                   c.v[0][1]=(c.v[0][1]+v[0][0]*1ll*b.v[0][1])%jsb;
                   
                   c.v[1][0]=v[1][1]*1ll*b.v[1][0]%jsb;
                   c.v[1][0]=(c.v[1][0]+v[1][0]*1ll*b.v[0][0])%jsb;
                   
                   c.v[1][1]=v[1][1]*1ll*b.v[1][1]%jsb;
                   c.v[1][1]=(c.v[1][1]+v[1][0]*1ll*b.v[0][1])%jsb;
                   return c;
                   }
       inline yd operator +=(const yd &b)
       {
                   v[0][0]=(v[0][0]+b.v[0][0])%jsb;
                   v[0][1]=(v[0][1]+b.v[0][1])%jsb;
                   v[1][0]=(v[1][0]+b.v[1][0])%jsb;
                   v[1][1]=(v[1][1]+b.v[1][1])%jsb;
                   }
}pre[MAXN],val[MAXN];
struct node
{
       yd sum,lazy;
       bool ha;
}t[MAXN*4];
int initsum[MAXN];
int n,m;
int l,r;
void build(int now,int x,int y)
{
     if(x==y)return;
     int mid=(x+y)>>1;
     build(now*2,x,mid);
     build(now*2+1,mid+1,y);
}
yd w;
void down(int x,int sx,int sy)
{
     if(t[x].ha==0)return;
     if(sx==sy)return;
     int mid=(sx+sy)>>1;
     t[x].ha=0;t[x*2].ha=t[x*2+1].ha=1;
     w=t[x].lazy;
     t[x*2].lazy+=w;
     t[x*2].sum+=w*pre[mid-sx];
     w=w*val[mid+1-sx];
     t[x*2+1].lazy+=w;
     t[x*2+1].sum+=w*pre[sy-mid-1];
     t[x].lazy.v[0][0]=t[x].lazy.v[0][1]=t[x].lazy.v[1][1]=t[x].lazy.v[1][0]=0;
}    
void putit(int x,int sx,int sy)
{
     //printf("%d\n",x);
     t[x].ha=1;
     t[x].sum+=val[sx-l+1]*pre[sy-sx];
     t[x].lazy=val[sx-l+1];
}    
void add(int now,int sx,int sy)
{
     down(now,sx,sy);
     if(l<=sx&&sy<=r)
     {
                               putit(now,sx,sy);
                               return;
                               }
     int mid=(sx+sy)>>1;
     if(l<=mid)add(now*2,sx,mid);
     if(r>=mid+1)add(now*2+1,mid+1,sy);
     t[now].sum=t[now*2].sum;
     t[now].sum+=t[now*2+1].sum;
}
yd ask(int now,int sx,int sy)
{
           down(now,sx,sy);
           if(l<=sx&&sy<=r)return t[now].sum;
           yd ans={};
           int mid=(sx+sy)>>1;
           if(l<=mid)ans+=ask(now*2,sx,mid);
           if(r>=mid+1)ans+=ask(now*2+1,mid+1,sy);
           return ans;
}
void init()
{
     for(int i=1;i<=n;i++){read(initsum[i]);initsum[i]=(initsum[i]+initsum[i-1])%jsb;}
     val[0].v[0][0]=val[0].v[1][1]=1;
     val[1].v[1][1]=val[1].v[0][1]=val[1].v[1][0]=1;
     for(int i=2;i<=n;i++)val[i]=val[i-1]*val[1];
     pre[0]=val[0];for(int i=1;i<=n;i++)pre[i]=val[i],pre[i]+=pre[i-1];
     build(1,1,n);
}
int main()
{
    scanf("%d%d",&n,&m);
    init();
    while(m--)
    {
              int opt;read(opt);read(l);read(r);
              if(opt==1)add(1,1,n);
              else
              {
                  int d=(initsum[r]-initsum[l-1])%jsb;
                  yd ws={};ws=ask(1,1,n);
                  d=(d+ws.v[0][1])%jsb;
                  if(d<0)d+=jsb;
                  print(d);
                  }
                  }
    return 0;
}