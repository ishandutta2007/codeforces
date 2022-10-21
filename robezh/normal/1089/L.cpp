#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm> 
#include <queue>
#define heap priority_queue
#define int long long
using namespace std;
const int maxn = 100000;
int n,k;
int a[maxn+1];
int b[maxn+1];
vector<int> c[maxn+1];
vector<int> d;
heap<int> H;
bool cmp(int x,int y)
{
	return x>y;
}
main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt","r",stdin);
	cin >> n >> k;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	for (int i=1; i<=n; i++)
		cin >> b[i];
	
	for (int i=1; i<=n; i++)
		c[a[i]].push_back(b[i]);
	
	for (int i=1; i<=k; i++)
	{
		sort(c[i].begin(),c[i].end(),cmp);
		for (int j=1; j<(int) c[i].size(); j++)
			d.push_back(c[i][j]);
	}
	
	sort(d.begin(),d.end());
	
	int p = 0;
	int res = 0;
	for (int i=1; i<=k; i++)
		if (c[i].size()==0)
		{
			res+=d[p];
			p++;
		}
	
	
	cout << res << '\n';
	return 0;
}