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

#define MX 105

char s[MX];

bool yes(int n)
{
	for(int i=0;i<n;)
	{
		int j = i+1;
		for(;j<n && s[j]==s[i];j++){}
		if(j-i>=7) return true;
		i=j;
	}
	return false;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in1.in","r",stdin);
	#endif
	
	scanf("%s",s);	
	int n = strlen(s);
	puts( yes(n) ? "YES" : "NO");
	
	return 0;
}