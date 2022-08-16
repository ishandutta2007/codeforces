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

#define INF 1000000000000000000ll

LL n;
LL mn = INF, mx = -INF;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in1.in","r",stdin);
	#endif
	
	n = SI;
	for(LL a=1;a*a*a<=n;a++) if(n%a==0)
	{
		LL bc = n/a;
		for(LL b = a;b*b<=bc;b++) if(bc%b==0)
		{
			LL c = bc/b;
			
			mn = min(mn,(a+2)*(b+2)*(c+1)-n);
			mn = min(mn,(a+1)*(b+2)*(c+2)-n);
			mn = min(mn,(a+2)*(b+1)*(c+2)-n);
			
			mx = max(mx,(a+1)*(b+2)*(c+2)-n);
			mx = max(mx,(a+2)*(b+1)*(c+2)-n);
			mx = max(mx,(a+2)*(b+2)*(c+1)-n);
		}
	}

	cout<<mn<<" "<<mx<<endl;	
			
	return 0;
}