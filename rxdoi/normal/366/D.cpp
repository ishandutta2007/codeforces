#include<cstdio>
#include<cctype>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
#define Mid (L+R>>1)
using namespace std;

int IN()
{
	int c,x;
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

const int N=1000+19,M=3000+19,oo=(1<<30)-1;
struct Edge {int a,b,L,R;} E[M];
int Fa[N],n,m,Ans=-1,L,R,res;

int Getf(int x) {return Fa[x]==x?x:Fa[x]=Getf(Fa[x]);}
void Union(int x,int y)
{
	int fx=Getf(x),fy=Getf(y);
	if (fx!=fy) Fa[fx]=fy;
}
bool Check(int x,int y)
{
	For(i,1,n+1) Fa[i]=i;
	For(i,0,m) if (E[i].L<=y&&E[i].R>=x) Union(E[i].a,E[i].b);
	return Getf(1)==Getf(n);
}
int Calc(int x)
{
	L=1,R=1e6+1,res=oo;
	while (L<=R)
		if (Check(x,Mid)) res=Mid,R=Mid-1;else L=Mid+1;
	return x>=res?res:oo;
}

int main()
{
	n=IN(),m=IN();
	For(i,0,m) E[i]=(Edge){IN(),IN(),IN(),IN()};
	For(i,0,m) Ans=max(Ans,E[i].R-Calc(E[i].R)+1);
	~Ans?printf("%d\n",Ans):puts("Nice work, Dima!");
}