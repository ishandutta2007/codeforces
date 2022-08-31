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

#define MX 100005

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in1.in","r",stdin);
	#endif
	
	LL n=SI,m=SI,a=SI,b=SI,r=0;
	a--; b--;
	
	int ar = a/m, br = b/m, ac = a%m, bc = b%m;
	
	if(ar==br) r = 1;
	else if(ar+1==br)
	{
		if(ac==0 && (bc==m-1 || b==n-1)) r = 1;
		else r = 2;
	}
	else
	{
		if(ac==0)
		{
			if(bc==m-1 || b==n-1) r = 1;
			else r = 2;
		}
		else if(bc==m-1 || b==n-1) r = 2;
		else
		{
			r = 3 - ((ac-1)==bc);
		}
	}
	
	cout<<r<<endl;
	
	return 0;
}