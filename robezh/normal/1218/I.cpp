#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <map>
#include <string>
#define ii pair<int,int>
#define X first
#define Y second
using namespace std;
const int maxn = 2000;
const int maxx = 4*maxn;
int n;
char a[maxn+1][maxn+1];
char b[maxn+1][maxn+1];
int f[maxn+1][maxn+1];

int w[maxn+1];


vector<int> V[maxx+1];
int num[maxx+1];
int low[maxx+1];
bool avail[maxx+1];
int cnt;
stack<int> stk;
vector<vector<int> > SCC;
int flag[maxx+1];
vector<ii> edges;

vector<int> mustBeTrue;
vector<string> res;

int N;

void addEdge(int x,int y)
{
	//cout << x << ' ' << y << '\n';
	edges.push_back(ii(x,y));
	V[x].push_back(y);
}

void init()
{
	memset(num,0,sizeof(num));
	memset(avail,true,sizeof(avail));
	memset(flag,-1,sizeof(flag));
}

void minimize(int& a,int b)
{
	if (b<a) a=b;
}

void dfs(int u)
{
	cnt++;
	num[u] = cnt;
	low[u] = N + 1;
	stk.push(u);
	
	for (auto it=V[u].begin(); it!=V[u].end(); it++)
	{
		int v = *it;
		if (avail[v])
		{
			if (num[v]!=0)
				minimize(low[u],num[v]);
			else
			{
				dfs(v);
				minimize(low[u],low[v]);
			}
		}
	}
	
	if (low[u]>=num[u])
	{
		int v;
		vector<int> newSCC;
		newSCC.clear();
		do
		{
			v=stk.top();
			stk.pop();
			newSCC.push_back(v);
			avail[v] = false;
		}
		while (v!=u);
		SCC.push_back(newSCC);
	}
}

void findSCC()
{
	init();
	for (int i=1; i<=N; i++)
		if (avail[i]) dfs(i);
}

int opposite(int x)
{
	if (x<=2*n)
		x+=2*n;
	else
		x-=2*n;
	return x;
}

void assignFlag()
{
	findSCC();
	
	for (auto it=SCC.rbegin(); it!=SCC.rend(); it++)
	{
		for (auto jt=(*it).begin(); jt!=(*it).end(); jt++)
		{
			if (flag[*jt]==-1)
			{
				int u=*jt;
				flag[u] = false;
				flag[opposite(u)] = true;
			}
		} 
	}
}



int main()
{
	ios_base::sync_with_stdio(0);
	
	cin >> n;
	for (int i=1; i<=n; i++)
	for (int j=1; j<=n; j++)
		cin >> a[i][j];
	for (int i=1; i<=n; i++)
	for (int j=1; j<=n; j++)
		cin >> b[i][j];
	
	for (int i=1; i<=n; i++)
	for (int j=1; j<=n; j++)
		f[i][j] = abs((int) b[i][j] - (int) a[i][j]);
	
	for (int i=1; i<=n; i++)
	{
		char c;
		cin >> c;
		w[i] = (int) (c - '0');
	}
	
	// 1->n: r(i)
	// n+1 -> n+n: c(j)
	
	N = 4*n;
	
	for (int i=1; i<=n; i++)
	for (int j=1; j<=n; j++)
	if (f[i][j])
	{
		if (w[i]==1 and w[j]==1)
		{
			addEdge(opposite(i),n+j);
			addEdge(opposite(n+j),i);
			addEdge(n+j,opposite(i));
			addEdge(i,opposite(n+j));
		}
		else
		if (w[i]==1)
		{
			addEdge(opposite(n+j),n+j);
		}
		else
		if (w[j]==1)
		{
			addEdge(opposite(i),i);
			
		}
		else
		{
			cout << -1;
			return 0;
		}
	}
	else
	{
		if (w[i]==1 and w[j]==1)
		{
			addEdge(i,n+j);
			addEdge(n+j,i);
			addEdge(opposite(i),opposite(n+j));
			addEdge(opposite(n+j),opposite(i));
		}
		else
		if (w[j]==1)
		{
			addEdge(i,opposite(i));
		}
		else
		if (w[i]==1)
		{
			addEdge(n+j,opposite(n+j));
		}
	}
	
	assignFlag();
	
	/*for (int i=1; i<=4*n; i++)
		cout << flag[i] << ' ';*/
	
	for (int i=1; i<=2*n; i++)
	if (!(flag[i] ^ flag[opposite(i)]))
	{
		cout << -1;
		return 0;
	}
	
	for (ii e: edges)
	{
		if (flag[e.X] and !flag[e.Y])
		{
			cout << -1;
			return 0;
		}
	}
	
	
	
	for (int i=1; i<=2*n; i++)
	{
		if (1<=i and i<=n)
		{
			if (flag[i])
				res.push_back("row "+to_string(i-1));
		}
		else
		{
			if (flag[i])
				res.push_back("col "+to_string(i-n-1));
		}
	}
	
	cout << res.size() << '\n';
	for (int i=0; i<res.size(); i++)
		cout << res[i] << '\n';
			
	
	
	
	return 0;
}