using namespace std;

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

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PI;

#define SI ({int x;scanf("%d",&x);x;})
#define SET(v,x) memset(v,x,sizeof v)

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)
#define TC REP(kase,SI)

#define SZ(v) int(v.size())
#define PB(x) push_back(x)
#define ALL(v) (v).begin(),(v).end()
#define SORT(v) sort(ALL(v))

#define MP(x,y) make_pair(x,y)
#define F first
#define S second

#define MX 100005

int a[1005],n;

int main()
{
	
	{
		n=SI;
		REP(i,n) a[i]=SI;
		sort(a,a+n);

		int count=0,mx=0,now=0,j;
		
		for(int i=0;i<n;i++)
		{
			count++; now=1;
			for(j=i+1;j<n;j++)
			{
				if(a[j]==a[j-1]) now++;
				else break;
			}

			mx=max(mx,now);
			i=j-1;
		}

		printf("%d %d\n",mx,count);
	}

	return 0;
}