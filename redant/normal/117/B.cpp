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
#define LET(x,a) __typeof(a) x(a)
#define IFOR(i,a,b) for(LET(i,a);i!=(b);++i)
#define EACH(it,v) IFOR(it,v.begin(),v.end())
#define SORT(v) sort(ALL(v))
#define SZ(v) int((v).size())
#define SI ({int x;scanf("%d",&x);x;})


#define MX 100005

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in1.in","r",stdin);
	#endif
	
	int a = SI, b = SI, m = SI;
	int m1 = 1000000000%m;
	
	for(int i=0;i<min(a+1,m);i++)
	{
		int y = (m - (1ll*i*m1)%m)%m;
		if(y<=b) continue;
		printf("1 %09d\n",i);
		return 0;
	}
	
	puts("2");
		
	return 0;
}