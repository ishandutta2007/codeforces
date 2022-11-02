// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <functional>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef pair<int,int> PII;
priority_queue<PII> q;
map<int,int> app;
int main()
{
	int n,r;
	scanf("%d",&n);
	while ( n-- ) {
		scanf("%d",&r);
		app[r]++;
	}
	FOR(it,app) q.push(make_pair(it->second,it->first));
	vector<int> sol;
	while ( SZ(q)>=3 ) {
		PII a=q.top(); q.pop();
		PII b=q.top(); q.pop();
		PII c=q.top(); q.pop();
		sol.push_back(a.second);
		sol.push_back(b.second);
		sol.push_back(c.second);
		if ( a.first>1 ) q.push(make_pair(a.first-1,a.second));
		if ( b.first>1 ) q.push(make_pair(b.first-1,b.second));
		if ( c.first>1 ) q.push(make_pair(c.first-1,c.second));
	}
	printf("%d\n",SZ(sol)/3);
	for ( int i=0; i<SZ(sol); i+=3 ) {
		sort(sol.begin()+i,sol.begin()+i+3,greater<int>());
		printf("%d %d %d\n",sol[i],sol[i+1],sol[i+2]);
	}
	return 0;
}