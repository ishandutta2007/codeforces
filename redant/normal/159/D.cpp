/*AnilKishore*India*/

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

#define MX 2003

bool isP[MX][MX];
char s[MX];
int n;
LL fromhere[MX];

int main()
{
	scanf("%s",s);
	n = strlen(s);
	SET(isP,false);
	for(int a=0,b=1;b<n;a++,b++)
		for(int x=a,y=b;x>=0&&y<n&&s[x]==s[y];x--,y++)
			isP[x][y] = true;
	for(int a=0,b=0;b<n;a++,b++)
		for(int x=a,y=b;x>=0&&y<n&&s[x]==s[y];x--,y++)
			isP[x][y] = true;
	for(int i=n-1;i>=0;i--)
	{
		LL cnt = 0;
		for(int j=i;j<n;j++) if(isP[i][j]) cnt++;
		fromhere[i] = fromhere[i+1] + cnt;
	}
	LL ans = 0;
	for(int i=0;i<n;i++)
	{
		LL cnt = 0;
		for(int j=i;j>=0;j--) if(isP[j][i])cnt++;
		ans += cnt * fromhere[i+1];
	}
	cout<<ans<<endl;
	return 0;
}