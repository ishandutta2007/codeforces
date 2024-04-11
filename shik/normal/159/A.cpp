// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <queue>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
#define MP make_pair
using namespace std;
typedef pair<string,string> PSS;
map<PSS,queue<int> >last;
set<PSS> sol;
int main()
{
	int n,d,t;
	string a,b;
	cin>>n>>d;
	while ( n-- ) {
		cin>>a>>b>>t;
		last[MP(a,b)].push(t);
		queue<int> &q=last[MP(b,a)];
		while ( !q.empty() && q.front()<t-d ) q.pop();
		if ( !q.empty() && q.front()<t ) sol.insert(MP(min(a,b),max(a,b)));
	}
	cout<<SZ(sol)<<endl;
	FOR(it,sol) cout<<it->first<<" "<<it->second<<endl;
	return 0;
}