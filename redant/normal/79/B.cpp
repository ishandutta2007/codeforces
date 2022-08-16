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

#define MX 100010

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in1.in","r",stdin);
	#endif
	
	VI v;
	
	int n = SI, m = SI, w = SI, q = SI;
	
	REP(i,w)
	{
		int a = SI - 1, b = SI - 1;
		v.PB(a*m+b);
	}
	
	SORT(v);
	
	REP(i,q)
	{
		int a = SI - 1, b = SI - 1;
		int id = a * m + b;
		
		VI::iterator it = lower_bound(ALL(v),id);
		
		if(it!=v.end() && id==*it){ puts("Waste"); continue; }
				
		++id;
		
		if(it!=v.begin()) id-=it-v.begin();
		
		if(id%3==1) puts("Carrots");
		if(id%3==2) puts("Kiwis");
		if(id%3==0) puts("Grapes");
	}
	
	
	return 0;
}