/* AnilKishore ( RedAnt ) */

// Happy Independence Day , India :)

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

#define MXN 30005

int isP[MXN+2];
int facs[MXN];

int main()
{
	int i,j,k;
	SET(isP,1);
	
	for(i=2;i<MXN;i++)
	{
		if(isP[i])
		{
			for(j=1;i*j<MXN;j++) facs[i*j]++;
			for(j=i*i;j<MXN;j+=i) isP[j]=0;
		}
	}

	int n = SI, r = 0;
	for(i=6;i<=n;i++) if(facs[i]==2) r++;
	printf("%d\n",r);

	return 0;
}