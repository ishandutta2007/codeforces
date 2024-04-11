#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define maxn 200005
#define ll long long
using namespace std;
int eg[maxn][2];
vector<int> nx[maxn];
int id[maxn], ans[maxn], tr[maxn];
int q[maxn], fr, ed;
bool inq[maxn];
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i < n; i++)
		scanf("%d%d", &eg[i][0], &eg[i][1]);
	for(int i = 1; i <= n; i++)
		scanf("%d", &tr[i]), 
		id[tr[i]] = i;
	for(int i = 1; i < n; i++)
		nx[eg[i][0]].push_back(id[eg[i][1]]), 
		nx[eg[i][1]].push_back(id[eg[i][0]]);
	for(int i = 1; i <= n; i++)
		if(!nx[i].empty())
			sort(nx[i].begin(), nx[i].end());
	fr = ed = 1;
	q[ed++] = 1;
	inq[1] = 1;
	while(fr < ed)
	{
		for(int i = 0; i < nx[q[fr]].size(); i++)
		{
			int v = tr[nx[q[fr]][i]];
			if(inq[v]) continue;
			q[ed++] = v, inq[v] = 1;
		}
	//	cout<<q[fr]<<endl;
		fr++;
	}
	for(int i = 1; i <= n; i++)
		if(q[i] != tr[i])
		{
		//	cout<<q[i]<<" "<<tr[i]<<" "<<i<<endl;
			printf("No\n");
			return 0;
		}
	printf("YES\n");
	return 0;
}