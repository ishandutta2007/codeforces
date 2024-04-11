#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;

const int Maxn=100000+19;
typedef long long LL;
vector<int> Dis[Maxn],B[Maxn],S;
LL A[Maxn],Be[Maxn],vis[Maxn],Min[Maxn],Tot[Maxn];
int x,y,cnt=0,n,m;
LL Ans1=0,Ans2=1;

void DFS(int u)
{
	if (vis[u]) return;vis[u]=1;
	for (int i=0;i<Dis[u].size();i++) DFS(Dis[u][i]);
	S.push_back(u);
}
void DFS_(int u)
{
	if (Be[u]!=-1) return;Be[u]=cnt;
	for (int i=0;i<B[u].size();i++) DFS_(B[u][i]);
}
void Kosaraju()
{
	for (int i=0;i<n;i++) DFS(i);
	for (int i=n-1;i>=0;i--)
		if (Be[S[i]]==-1) {DFS_(S[i]);cnt++;}
}

int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&A[i]);
	memset(Be,255,sizeof(Be));
	scanf("%d",&m);
	for (int i=0;i<m;i++)
	{
		scanf("%d%d",&x,&y);x--;y--;
		Dis[x].push_back(y);
		B[y].push_back(x);
	}
	Kosaraju();
	memset(Min,60,sizeof(Min));
	for (int i=0;i<n;i++) Min[Be[i]]=min(Min[Be[i]],A[i]);
	for (int i=0;i<n;i++) if (Min[Be[i]]==A[i]) Tot[Be[i]]++;
	for (int i=0;i<cnt;i++) Ans1+=Min[i],Ans2=Ans2*Tot[i]%1000000007;
	printf("%I64d %I64d\n",Ans1,Ans2);
	return 0;
}