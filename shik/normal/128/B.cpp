// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <queue>
#define N 100010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
struct P {
	string s;
	int l,r;
	P( string _s, int _l, int _r ):s(_s),l(_l),r(_r){}
};
bool operator <( const P &a, const P &b ) { return a.s>b.s; }
priority_queue<P> q;
char s[N];
int main()
{
	int n=strlen(gets(s+1)),k;
	scanf("%d",&k);
	if ( k>1LL*n*(n-1)/2+n ) return puts("No such line."),0;
	for ( int i=1; i<=n; i++ ) q.push(P(string("")+s[i],i,i));
	while ( --k ) {
		P p=q.top(); q.pop();
		if ( p.r==n ) continue;
		p.s+=s[++p.r];
		q.push(p);
	}
	printf("%s\n",q.top().s.c_str());
	return 0;
}