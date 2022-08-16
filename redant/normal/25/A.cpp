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

int main()
{
	int n,i,j,k;
	scanf("%d",&n);
	int ec=0,oc=0,ei=-1,oi=-1;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&k);
		if(k&1) oc++,oi=i;
		else ec++,ei=i;
	}

	printf("%d\n",ec==1?ei:oi);

	return 0;
}