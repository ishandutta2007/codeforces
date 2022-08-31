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

#define PB push_back
#define MP make_pair
#define SET(v,x) memset(v,x,sizeof(v))
#define ALL(v) (v).begin(),(v).end()

const int mxn = 305;
LL s = 0;
int d[mxn][mxn];

int main()
{
	int n,i,j,k;
	scanf("%d",&n);

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&d[i][j]);
			if(i<j) s+=d[i][j];
		}
	}

	scanf("%d",&k);

	while(k--)
	{
		int u, v, c;
		scanf("%d %d %d",&u, &v, &c);

		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				int nc = d[i][u] + c + d[v][j];
				if(nc<d[i][j])
				{
					s-=(d[i][j]-nc);
					d[i][j] = d[j][i] = nc;
				}
			}
		}

		cout<<s;
		printf(k==0?"\n":" ");
	}

	return 0;
}