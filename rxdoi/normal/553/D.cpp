#include<cstdio>
#include<cctype>
#include<vector>
#include<cstring>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
#define Pb push_back
using namespace std;

int IN()
{
	int c,x;
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

const int N=100000+19;
const double Eps=1e-11;
struct Edge {int y,nxt;} E[N*2];
int D[N],C[N],A[N],Last[N],vis[N],Q[N];
int n,m,k,cnt;
double L=0,R=1;
vector<int> V;

void Link(int x,int y)
{
	E[cnt]=(Edge){y,Last[x]};Last[x]=cnt++;
	E[cnt]=(Edge){x,Last[y]};Last[y]=cnt++;D[x]++,D[y]++;
}

bool Check(double t)
{
	int f=1,w=0,b=0;
	memset(vis,0,sizeof(vis));
	For(i,1,k+1) Q[++f]=A[i],vis[A[i]]=1;
	For(i,1,n+1) C[i]=D[i];
	while (f>w)
	{
		int x=Q[++w];
		for (int i=Last[x];~i;i=E[i].nxt)
			if (!vis[E[i].y]&&1.0*(--C[E[i].y])/D[E[i].y]<t) vis[Q[++f]=E[i].y]=1;
	}
	V.clear();
	For(i,1,n+1) if (!vis[i]) b=1,V.Pb(i);
	return b;
}

int main()
{
	memset(Last,-1,sizeof(Last));
	n=IN(),m=IN(),k=IN();
	For(i,1,k+1) A[i]=IN();
	For(i,0,m) Link(IN(),IN());
	while (R-L>Eps)
	{
		double Mid=(L+R)/2.0;
		if (Check(Mid)) L=Mid;else R=Mid;
	}
	Check(L);
	printf("%d\n",V.size());
	For(i,0,V.size()) printf("%d ",V[i]);puts("");
}