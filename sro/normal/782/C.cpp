#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#define pb push_back
#define mp make_pair
#define FILL(a,v) memset(a,v,sizeof(a))
#define ALL(a) (a).begin(),(a).end()
using namespace std;
using namespace __gnu_cxx;

vector<int> ljd[234012];
int a[234012],b[234012],n;
int col[234012];
vector<int> qgd;

void dfs(int stt)
{
	qgd.pb(stt);
	set<int> dd;dd.insert(col[qgd[qgd.size()-2]]);dd.insert(col[stt]);
	int yns=1; 
	for(int i=0;i<ljd[stt].size();i++)if(ljd[stt][i]!=qgd[qgd.size()-2])
	{
		while(dd.count(yns))yns++;
		col[ljd[stt][i]]=yns;
		yns++;
		dfs(ljd[stt][i]);
		qgd.pop_back();
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		scanf("%d %d",&a[i],&b[i]);
		ljd[a[i]].pb(b[i]);
		ljd[b[i]].pb(a[i]);
	}
	int mx=0;
	for(int i=1;i<=n;i++)if((int)ljd[i].size()>mx)mx=(int)ljd[i].size();
	printf("%d\n",mx+1);
	col[1]=1;
	qgd.pb(1);
	dfs(1);
	for(int i=1;i<=n;i++)printf("%d%c",col[i],i==n?'\n':' ');
	return 0;
}