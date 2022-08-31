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

int a[103];

int main()
{
	const int inf = 1000000;
	int n = SI,i,j,r=inf;

	for(i=0;i<n;i++) a[i]=SI;
	sort(a,a+n);

	int x = a[0];

	for(i=1;i<n;i++) if(a[i]!=x){ r=a[i]; break; }

	if(r==inf) puts("NO");
	else printf("%d\n",r);

	return 0;
}