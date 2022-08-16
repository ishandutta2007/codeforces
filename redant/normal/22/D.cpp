/*
LANG: C++
ID: AnilKishore
*/

#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cstdlib>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PI;

#define INF 100000000
#define PB push_back
#define MP make_pair
#define LL long long
#define SET(v,x) memset(v,x,sizeof(v))
#define ALL(v) (v).begin(),(v).end()
#define SI ({int x;scanf("%d",&x);x;})

vector<PI> V;
VI res;

int main()
{
	int n = SI, x, y, a, b;
	int i, j, k;

	for(i=0;i<n;i++)
	{
		a=SI; b=SI;
		x=min(a,b); y=max(a,b);
		V.PB( MP(y,x) );
	}

	sort(ALL(V));

	int last = -INF;
	for(i=0;i<n;i++)
	{
		x = V[i].second; y = V[i].first;
		if(x>last) last=y,res.PB(last);
	}

	printf("%d\n",res.size());
	for(i=0;i<res.size();i++) printf("%d ",res[i]);

	puts("");
	return 0;
}