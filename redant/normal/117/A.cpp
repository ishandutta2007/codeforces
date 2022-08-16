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

int m, p;

PI steps(int from,int to,int dir)
{
	if(dir==0)//up
	{
		if(from<=to) return MP(to-from,0);
		else return MP(m-1-from+m-1-to,1);
	}
	
	//down
	if(from>=to) return MP(-to+from,1);
	else return MP(from+to,0);
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in1.in","r",stdin);
	#endif
	
	int n = SI;
 	m = SI;
 	p = m + m - 2;
	
	while(n--)
	{
		int s = SI - 1, f = SI - 1, t = SI, r = 0;
		if(s==f){ printf("%d\n",t); continue; }
		int a = t%p;
		PI cur;
		if(a<m) cur = MP(a,0);
		else cur = MP(m-1-(a-(m-1)),1);
		cur = steps(cur.F,s,cur.S); r+=cur.F;
		cur = steps(s,f,cur.S); r+=cur.F;
		printf("%d\n",t+r);
	}
		
	return 0;
}