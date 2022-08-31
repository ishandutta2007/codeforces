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

#define MX 51

int R,C;
int a[MX][MX];
int x[3];

int get(int A[MX],int n)
{
	sort(x,x+3);
	int y[3], ans = 0;
	FOR(i,1,n) FOR(j,i+1,n)
	{
		y[0]=y[1]=y[2]=0;
		FOR(k,0,i) y[0]+=A[k];
		FOR(k,i,j) y[1]+=A[k];
		FOR(k,j,n) y[2]+=A[k];
		sort(y,y+3);
		ans+=(x[0]==y[0] && x[1]==y[1] && x[2]==y[2]);
	}
	return ans;
}

int main()
{
	#ifdef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	R=SI; C=SI;
	REP(i,R) REP(j,C) a[i][j]=SI;
	REP(i,3) x[i]=SI;
	
	int A[MX];

	REP(i,R)
	{
		A[i]=0;
		REP(j,C) A[i]+=a[i][j];
	}

	int ans = get(A,R);

	REP(j,C)
	{
		A[j]=0;
		REP(i,R) A[j]+=a[i][j];
	}

	ans += get(A,C);

	printf("%d\n",ans);

	return 0;
}