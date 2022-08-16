/* AnilKishore ( RedAnt ) */

#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>

#include <iostream>
#include <algorithm>
#include <string>

#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PI;

#define PB push_back
#define MP make_pair
#define ST first
#define ND second
#define SET(v,x) memset(v,x,sizeof(v))
#define ALL(v) (v).begin(),(v).end()
#define SZ(v) int(v.size())
#define SI ({int x;scanf("%d",&x);x;})

int a[103], d[103];
int vis[103], n;
int can[103][103];

int main()
{
	int i, j, k;
	n=SI;
	for(i=1;i<=n;i++) a[i]=SI;
	for(i=1;i<=n;i++)
	{
		d[i]=SI;
		can[i][i]=1;
		if(i-d[i]>0 ) can[i][i-d[i]]=can[i-d[i]][i]=1;
		if(i+d[i]<=n) can[i][i+d[i]]=can[i+d[i]][i]=1;
	}

	for(k=1;k<=n;k++) for(i=1;i<=n;i++) for(j=1;j<=n;j++)
		if(can[i][k]&can[k][j]) can[i][j]=1;

	int ok = 1;
	for(i=1;i<=n;i++) if(!can[a[i]][i]) ok=0;

	puts(ok?"YES":"NO");

	return 0;
}