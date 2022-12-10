#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
#define Pb push_back
using namespace std;

const int N=500*500+19;
struct Edge {int y,nxt;} E[N*4];
struct Res {int t,x;};
vector<Res> V;
char s[501][501];
int Last[N],vis[N],n,m,tot,cnt;

void Link(int x,int y)
{
	E[cnt]=(Edge){y,Last[x]};Last[x]=cnt++;
	E[cnt]=(Edge){x,Last[y]};Last[y]=cnt++;
}
void DFS(int x,int Fa)
{
	V.Pb((Res){0,x}),vis[x]=1;
	for (int i=Last[x];~i;i=E[i].nxt) if (!vis[E[i].y]) DFS(E[i].y,x);
	if (~Fa) V.Pb((Res){1,x}),V.Pb((Res){2,x});
}

int main()
{
	memset(Last,-1,sizeof(Last));
	scanf("%d%d",&n,&m);
	For(i,0,n) scanf("%s",s[i]);
	For(i,0,n) For(j,0,m)
		if (s[i][j]!='#')
		{
			if (i&&s[i-1][j]!='#') Link((i-1)*m+j,i*m+j);
			if (j&&s[i][j-1]!='#') Link(i*m+j,i*m+j-1);
		}
	For(i,0,n) For(j,0,m)
		if (s[i][j]!='#'&&!vis[i*m+j]) DFS(i*m+j,-1);
	printf("%d\n",V.size());
	For(i,0,V.size()) printf("%c %d %d\n","BDR"[V[i].t],V[i].x/m+1,V[i].x%m+1);
}