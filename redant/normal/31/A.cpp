/*
LANG: C++
ID: AnilKishore ( RedAnt )
 */

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

int main()
{
	int a[102], n = SI, i, j, k;
	for(i=1;i<=n;i++) a[i]=SI;
	for(i=1;i<=n;i++) 
		for(j=1;j<=n;j++) if(i!=j)
			for(k=1;k<=n;k++) if(i!=k && j!=k)
				if(a[i]==a[j]+a[k])
				{
					printf("%d %d %d\n",i,j,k);
					return 0;
				}
	puts("-1");
	return 0;
}