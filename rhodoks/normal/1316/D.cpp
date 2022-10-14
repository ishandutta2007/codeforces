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

int dir[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
char p[10]="UDRL";
typedef pair<int,int> pii;

int x[MAXN][MAXN],y[MAXN][MAXN];
char s[MAXN][MAXN];
int num[MAXN][MAXN];
int n;
bool check(int x,int y)
{
	return x>=1 && x<=n && y>=1 && y<=n; 
}

int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			scanf("%d%d",&x[i][j],&y[i][j]);
	queue<pair<int,int> > q;
	queue<pair<int,int> > q2;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (x[i][j]==i && y[i][j]==j)
			{
				int X=i;
				int Y=j;
				q.push({i,j});
				s[i][j]='X';
				while (!q.empty())
				{
					int posx=q.front().first;
					int posy=q.front().second;
					q.pop();
					for (int k=0;k<4;k++)
					{
						int tox=posx+dir[k][0];
						int toy=posy+dir[k][1];
						if (check(tox,toy) && x[tox][toy]==X && y[tox][toy]==Y && !s[tox][toy])
						{
							q.push({tox,toy});
							s[tox][toy]=p[k^1];
						}
					}
				}
			}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (x[i][j]==-1 && y[i][j]==-1)
			{
				q.push({i,j});
				while (!q.empty())
				{
					int posx=q.front().first;
					int posy=q.front().second;
					q.pop();
					for (int k=0;k<4;k++)
					{
						int tox=posx+dir[k][0];
						int toy=posy+dir[k][1];
						if (check(tox,toy) && x[tox][toy]==-1 && y[tox][toy]==-1 && !s[tox][toy])
						{
							if (posx==i && posy==j)
								s[posx][posy]=p[k];
							q.push({tox,toy});
							s[tox][toy]=p[k^1];
						}
					}
				}
			}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (!s[i][j])
			{
				cout<<"INVALID"<<endl;
				return 0;
			}
	cout<<"VALID"<<endl;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
			cout<<s[i][j];
		cout<<endl;
	}
	return ~~(0^_^0);
}