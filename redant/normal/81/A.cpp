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
typedef pair<int,int> PI;

#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define F first
#define S second
#define SET(v,x) memset(v,x,sizeof v)
#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define SORT(v) sort(ALL(v))
#define SZ(v) int(v.size())
#define SI ({int x;scanf("%d",&x);x;})

#define MX 200005

char S[MX], ans[MX];
int n;

int main()
{
	scanf("%s",S);
	int pa=0, ps=0;

	while(1)
	{
		if(pa>1 &&  ans[pa-1]==ans[pa-2]){ pa-=2; continue; }
		if(!S[ps]) break;
		ans[pa++] = S[ps++];
	}

	ans[pa]='\0';
	puts(ans);
	
	return 0;
}