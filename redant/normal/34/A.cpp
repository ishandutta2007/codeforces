/*
PROG: 
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

int n,A[111];

int main()
{
	n=SI;
	int i;
	for(i=1;i<=n;i++) A[i]=SI;
	
	int mn = abs(A[1]-A[n]), x = 1, y = n;
	for(i=1;i+1<=n;i++)
	{
		int nw = abs(A[i]-A[i+1]);
		if(nw<mn){ mn=nw; x=i; y=i+1; }
	}

	printf("%d %d\n",x,y);

	return 0;
}