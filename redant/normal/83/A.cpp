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

int a[MX];

int main()
{
	int n = SI;	
	REP(i,n) a[i]=SI;
	LL ans = 0;
	for(int i=0;i<n;)
	{
		int j = i+1;
		while(j<n&&a[i]==a[j]) j++;
		ans+=(j-i)*1ll*(j-i+1);
		i=j;
	}
	cout<<(ans>>1)<<endl;

	return 0;
}