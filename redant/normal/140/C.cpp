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

int A[MX], b[3];
PI cnt[MX];
vector<pair<int,PI> > V;
int m;

void solve()
{
	int a=0, b=1, c=2;
	while(c<m)
	{
		while(a<m && cnt[a].S==0) a++;
		while(b<m && (a>=b || cnt[b].S==0) ) b++;
		while(c<m && (b>=c || cnt[c].S==0) ) c++;
		if(c>=m) break;
		V.PB(MP(cnt[a].F,MP(cnt[b].F,cnt[c].F)));
		cnt[a].S--; cnt[b].S--; cnt[c].S--;
	}
}

void solve2()
{
	priority_queue<PI> pq;
	REP(i,m) pq.push(MP(cnt[i].S,cnt[i].F));
	while(pq.size()>=3)
	{
		PI x = pq.top(); pq.pop(); x.F--;
		PI y = pq.top(); pq.pop(); y.F--;
		PI z = pq.top(); pq.pop(); z.F--;
		V.PB(MP(x.S,MP(y.S,z.S)));
		if(x.F) pq.push(x);
		if(y.F) pq.push(y);
		if(z.F) pq.push(z);
	}
}


int main()
{	
	int n = SI;
	REP(i,n) A[i] = SI;
	
	sort(A,A+n);
	
	m=0;
	for(int i=0;i<n;)
	{
		int j = i+1;
		while(j<n && A[j]==A[i]) j++;
		cnt[m++] = MP(A[i],j-i);
		i=j;
	}

	solve2();
	
	printf("%d\n",SZ(V));

	EACH(it,V)
	{
		b[0] = it->F, b[1] = it->S.F, b[2] = it->S.S;
		sort(b,b+3);
		printf("%d %d %d\n",b[2],b[1],b[0]);
	}

	return 0;
}