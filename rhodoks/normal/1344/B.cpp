#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 1100
#define MAXM 410000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int visit[MAXN][MAXN];;

typedef pair<int,int> pii;
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
char s[MAXN][MAXN];
int n,m;

bool check(int x,int y)
{
	return x>=0 && x<n && y>=0 && y<m;
}

void bfs(int x,int y)
{
	//cout<<x<<' '<<y<<endl;
	queue<pii> q;
	q.push({x,y});
	visit[x][y]=1;
	while (!q.empty())
	{
		int px=q.front().first;
		int py=q.front().second;
		q.pop();
		for (int k=0;k<4;k++)
		{
			int tx=px+dir[k][0];
			int ty=py+dir[k][1];
			if (check(tx,ty) && !visit[tx][ty] && s[tx][ty]=='#')
			{
				visit[tx][ty]=1;
				q.push({tx,ty});
			}
		}
	}
}

int main()
{
	cin>>n>>m;
	for (int i=0;i<n;i++)
		scanf("%s",&s[i]);
	bool f=true;
	int tc=0,tr=0;
	for (int i=0;i<n;i++)
	{
		int cnt=0;
		for (int j=0;j<m;j++)
			if (j==0 && s[i][j]=='#' || j && s[i][j-1]=='.' && s[i][j]=='#')
				cnt++;
		tr+=(cnt==0);
		if (cnt>=2)
		{
			f=false;
			break;
		}
	}
	for (int j=0;j<m;j++)
	{
		int cnt=0;
		for (int i=0;i<n;i++)
			if (i==0 && s[i][j]=='#' || i && s[i-1][j]=='.' && s[i][j]=='#')
				cnt++;
		tc+=(cnt==0);
		if (cnt>=2)
		{
			f=false;
			break;
		}
	}
	if (tc==0 && tr==0 || tc && tr)
		;
	else
		f=0;
	if (!f)
	{
		cout<<-1;
		return 0;
	}
	int ans=0;
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			if (s[i][j]=='#' && !visit[i][j])
			{
				bfs(i,j);
				ans++;
			}
	cout<<ans;
	return ~~(0^_^0);
}