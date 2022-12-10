#include<cstdio>
#include<cctype>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

int IN()
{
	int c,x;
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

const int N=1e5+19;
int A[N],Fa[N],n,m,x,y;

int Getf(int x) {return Fa[x]==x?x:Fa[x]=Getf(Fa[x]);}

bool Bus()
{
	if (m!=n-1) return 0;
	int cnt=0;
	For(i,1,n+1)
	{
		if (A[i]<1||A[i]>2) return 0;
		cnt+=(A[i]==1);
	}
	return cnt==2;
}
bool Ring()
{
	if (m!=n) return 0;
	For(i,1,n+1) if (A[i]!=2) return 0;
	return 1;
}
bool Star()
{
	if (m!=n-1) return 0;
	int cnt=0;
	For(i,1,n+1) cnt+=(A[i]>1);
	return cnt==1;
}

int main()
{
	n=IN(),m=IN();
	For(i,1,n+1) Fa[i]=i;
	For(i,0,m)
	{
		int fx=Getf(x=IN()),fy=Getf(y=IN());
		if (fx!=fy) Fa[fx]=fy;A[x]++,A[y]++;
	}
	For(i,1,n+1) if (Getf(i)!=Getf(1)) return puts("unknown topology"),0;
	printf("%s topology",Bus()?"bus":Ring()?"ring":Star()?"star":"unknown");
}