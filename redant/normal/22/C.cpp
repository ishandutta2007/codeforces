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

const int mxn = 100003;
int ver[mxn];

int main()
{
	int n = SI, m = SI, v = SI, cut;
	int i, j, k;
	cut = 2;

	for(i=1;i<=n;i++) ver[i]=i;

	k = ver[cut];
	ver[cut] = ver[v];
	ver[v] = k;

	LL minm = n-1;
	LL n1 = cut, n2 = n - cut + 1, maxm = (n1*(n1-1))/2 + (n2*(n2-1))/2;
	//cout<<n1<<","<<n2<<endl<<"min="<<minm<<" , max="<<maxm<<endl;
	if(m<minm || m>maxm){ printf("-1\n"); exit(0); }

	for(i=1;i<cut;i++,m--) printf("%d %d\n",ver[i],v);
	for(i=cut+1;i<=n;i++,m--) printf("%d %d\n",v,ver[i]);

	for(i=1;i<cut&&m>0;i++)
		for(j=i+1;j<cut&&m>0;j++)
		{
			printf("%d %d\n", ver[i], ver[j]);
			m--;
		}

	for(i=cut+1;i<=n&&m>0;i++)
		for(j=i+1;j<=n&&m>0;j++)
		{
			printf("%d %d\n", ver[i], ver[j]);
			m--;
		}

	return 0;
}