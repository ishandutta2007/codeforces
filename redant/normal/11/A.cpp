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
	int n, d, p, c, x, r = 0;
	n=SI; d=SI;
	p=SI; n--;
	
	while(n--)
	{
		c = SI;
		if(c<=p)
		{
			x = (p+1-c+d-1)/d;
			r+=x;
			c += d*x;
		}
		p = c;
	}

	printf("%d\n",r);

	return 0;
}