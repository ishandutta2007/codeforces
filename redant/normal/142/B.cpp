/* ID: AnilKishore ( RedAnt ) */

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
#define EACH(it,v) for(typeof((v).begin()) it = (v).begin();it!=(v).end();it++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define SORT(v) sort(ALL(v))
#define SZ(v) int(v.size())
#define SI ({int x;scanf("%d",&x);x;})

#define MX 100005

int g(int n)
{
	int r = (n/4)*4;
	if(n%4==1) r+=2;
	else if(n%4>1) r+=4;
	return r;
}

int f(int R,int C)
{
	int r = (C+1)/2, c = C/2;
	r = (R/2)*(r+c) + ((R%2)?r:0);
	return max(r,R*C-r);
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in1.in","r",stdin);
	#endif
	
	int n = SI, m = SI, r = 0;
	
	if(n==1 || m==1) r = m*n;
	else if(n==2||m==2) r = g(max(n,m));
	else r = max(f(n,m),f(m,n));
	
	printf("%d\n",r);
			
	return 0;
}