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

string A[5] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard" };

int main()
{
	LL n = SI;

	LL f = 1;
	LL s = 0, c = 5;
	
	while(s+c<n){ s+=c; c*=2; f*=2; }

	LL m = n - s - 1;

	cout<<A[int(m/f)]<<endl;

	return 0;
}