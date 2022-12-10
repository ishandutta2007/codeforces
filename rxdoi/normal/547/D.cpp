#include<set>
#include<cstdio>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
#define mp make_pair
using namespace std;

const int N=4e5+19,top=2e5;
typedef pair<int,int> PII;
set<PII> S;
set<int> E[N];
int x[N],y[N],n;

void DFS(int x)
{
	if (E[x].size())
	{
		int y=*E[x].begin();
		S.insert(mp(x,y));
		E[x].erase(y),E[y].erase(x);
		DFS(y);
	}
}

int main()
{
	scanf("%d",&n);
	For(i,1,n+1)
		scanf("%d%d",&x[i],&y[i]),
		E[x[i]].insert(y[i]+top),E[y[i]+top].insert(x[i]);
	For(i,1,2*top+1) if (E[i].size()&1) DFS(i);
	For(i,1,2*top+1) while (E[i].size()) DFS(i);
	For(i,1,n+1) putchar(S.count(mp(x[i],y[i]+top))?'r':'b');
}