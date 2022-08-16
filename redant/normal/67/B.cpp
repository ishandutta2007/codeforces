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

#define MXN 1010

int n, k;
int b[MXN];
VI a;

int main()
{
	n=SI; k=SI;
	REP(i,n) b[i+1] = SI;

	a.PB(n);

	for(int i=n-1,j=n+k-1;i>0;i--,j--)
	{
		if(b[i]==0){ a.insert(a.begin(),i); continue; }

		int k = b[i];
		for(VI::iterator it = a.begin();it!=a.end();it++)
		{
			if(*it>=j) k--;
			if(k==0){  it++; a.insert(it,i); break; }
		}
	}

	for(VI::iterator it = a.begin();it!=a.end();it++)
		printf("%d ",*it);

	puts("");


	return 0;
}