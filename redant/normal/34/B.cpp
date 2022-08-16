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

int main()
{
	VI A;
	int n=SI, k=SI, i, j, s = 0;
	for(i=0;i<n;i++)
	{
		j=SI; if(j<0) A.PB(-j);
	}

	sort(ALL(A));

	for(i=SZ(A)-1,j=0;i>=0&&j<k;i--)
		s+=A[i],j++;

	printf("%d\n",s);

	return 0;
}