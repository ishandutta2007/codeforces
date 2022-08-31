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

int n,m,N,M;
int f[3];

int main()
{
	int i,j,k;
	n=SI;
	for(i=0;i<n;i++)
	{
		m=SI; m%=3;
		f[m]++;
	}

	int r = f[0]/2;
	r+=min(f[1],f[2]);

	printf("%d\n",r);

	return 0;
}