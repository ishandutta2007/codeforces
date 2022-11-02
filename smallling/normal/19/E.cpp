#include<cstdio>
#include<algorithm>

using namespace std;

struct lhy{
	int x,y,next;
}edge[2000010];

int Cnt[1000010],son[1000010],color[1000010],flag[1000010],F[1000010],T[1000010],ToFa[1000010],fa[1000010],instack[1000010];
int x,y,n,m,ToT,tot,cnt,FirstOdd;

inline void add(int x,int y)
{
	edge[++tot].x=x;edge[tot].y=y;edge[tot].next=son[x];son[x]=tot;
}

void dfs(int x,int C)
{
	instack[x]=1;
	color[x]=C;
	flag[x]=1;
	for(int i=son[x];i;i=edge[i].next)
	{
		if(edge[i].y==x)continue;
		if(fa[x]==edge[i].y)continue;
		if(fa[edge[i].y]==x)
		{
			Cnt[edge[i].y]=1;
			continue;
		}
		if(!flag[edge[i].y])
		{
			ToFa[edge[i].y]=i;
			fa[edge[i].y]=x;
			dfs(edge[i].y,C^1);
			F[x]+=F[edge[i].y];
			T[x]+=T[edge[i].y];
		}
		else
		{
			if(instack[edge[i].y])
				if(color[edge[i].y]==color[x])cnt++,FirstOdd=i,F[x]++;
				else T[x]++;
			else
				if(color[edge[i].y]==color[x])F[x]--;
				else T[x]--;
		}
	}
	instack[x]=0;
}

char nc(){static char buf[100000],*p1=buf+100000,*pend=buf+100000;if (p1==pend) p1=buf,pend=buf+fread(buf,1,100000,stdin);return *p1++;}
void read(int &x){char ch=nc();x=0;for (;ch<'0';ch=nc());for (;ch>='0';ch=nc()) x=x*10+ch-'0';}

struct Ostream_fwrite{
		char *buf,*p1,*pend;
		Ostream_fwrite(){buf=new char[100000];p1=buf;pend=buf+100000;}
		void out(char ch){
			if (p1==pend){
				fwrite(buf,1,100000,stdout);p1=buf;
			}
			*p1++=ch;
		}
		void print(int x){
			static char s[15],*s1;s1=s;
			if (!x)*s1++='0';
			while(x)*s1++=x%10+'0',x/=10;
			while(s1--!=s)out(*s1);
		}
		void println(int x){
			static char s[15],*s1;s1=s;
			if (!x)*s1++='0';
			while(x)*s1++=x%10+'0',x/=10;
			while(s1--!=s)out(*s1); out('\n');
		}
		void flush(){if (p1!=buf){fwrite(buf,1,p1-buf,stdout);p1=buf;}}
		~Ostream_fwrite(){flush();}
}Ostream;
inline void print(int x){Ostream.print(x);}
inline void println(int x){Ostream.println(x);}

int main()
{
	int Flag=0,nowx;
	read(n),read(m);
	for(int i=1;i<=m;i++)
	{
		read(x),read(y),add(x,y),add(y,x);
		if(x==y)
		{
			Flag=1;
			nowx=x;
			FirstOdd=tot-1;
		}
	}
	for(int i=1;i<=n;i++)
		if(!flag[i])dfs(i,0);
	if(Flag&&!cnt)
	{
		int ans;
		for(int i=1;i<=tot;i+=2)
			if(edge[i].x==edge[i].y)
			{
				if(ToT==1)
				{
					println(0);
					return 0;
				}
				ans=(i+1)/2;
			}
		println(ToT);
		if(ToT)println(ans);
		return 0;
	}
	if(Flag&&cnt)
	{
		println(0);
		return 0;
	}
	if(!cnt)
	{
		println(m);
		for(int i=1;i<m;i++)print(i),Ostream.out(' ');
		if(m)println(m);
	}
	else
	{
		int Max=0;
		for(int i=1;i<=m;i++)
			flag[i]=0;
		if(cnt==1)
		{
			flag[(FirstOdd+1)/2]=1;
			if((FirstOdd+1)/2>Max)Max=(FirstOdd+1)/2;
			ToT++;
		}
		for(int i=1;i<=n;i++)
			if(F[i]==cnt&&!T[i]&&!Cnt[i])
			{
				flag[(ToFa[i]+1)/2]=1;
				if((ToFa[i]+1)/2>Max)Max=(ToFa[i]+1)/2;
				ToT++;
			}
		println(ToT);
		for(int i=1;i<Max;i++)
			if(flag[i])print(i),Ostream.out(' ');
		if(ToT)println(Max);
	}
}