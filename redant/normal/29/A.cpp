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

#define MX 111

int spit[MX];
int pos[MX];

int main()
{
	int n = SI, i, j, k, ya = 0;
	
	for(i=0;i<n;i++)
	{
		pos[i]=SI; spit[i]=SI;
	}

	for(i=0;i<n&&!ya;i++)
	{
		for(j=i+1;j<n&&!ya;j++)
			if(pos[i]+spit[i] == pos[j] && pos[j]+spit[j]==pos[i])
					ya=1;
	}

	puts(ya?"YES":"NO");

	return 0;
}