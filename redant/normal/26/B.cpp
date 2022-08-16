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

#define MXN 1000005

char S[MXN];

int main()
{
	int i, s = 0, r = 0, j;
	
	gets(S);
	int n = strlen(S);

	for(i=0;i<n;i++)
	{
		if(S[i]=='(') s++;
		else
		{
			if(s>0) s--;
			else r++;
		}
	}
	
	r+=s;

	printf("%d\n",n-r);

	return 0;
}