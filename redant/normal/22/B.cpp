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

int main()
{
	int n = SI, m = SI, r = 0, i, j, k;
	char sa[33];
	int sum[33][33];

	for(i=1;i<=n;i++) 
	{
		scanf(" %s",sa);
		for(j=1;j<=m;j++)
		{
			sum[i][j]=sa[j-1]-'0';
		}
	}

	for(i=1;i<=n;i++) for(j=1;j<=m;j++)
		sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];

	for(int x1=1;x1<=n;x1++) for(int y1=1;y1<=m;y1++)
		for(int x2=x1;x2<=n;x2++) for(int y2=y1;y2<=m;y2++)
		{
			int s = sum[x2][y2] - sum[x2][y1-1] - sum[x1-1][y2] + sum[x1-1][y1-1];
			if(s==0) r = max( r , 2*(x2-x1+1+y2-y1+1) );
		}

	printf("%d\n",r);
	return 0;
}