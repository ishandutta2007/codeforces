// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define N 50010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
#define MP make_pair
using namespace std;
typedef pair<int,int> PII;
char s[N];
priority_queue<PII> q;
int main()
{
	int n=strlen(gets(s)),a,b,now=0;
	long long ans=0;
	for ( int i=0; i<n; i++ ) {
		if ( s[i]=='(' ) now++;
		else if ( s[i]==')' ) now--;
		else {
			scanf("%d%d",&a,&b);
			now--;
			s[i]=')';
			ans+=b;
			q.push(MP(b-a,i));
		}
		if ( now<0 ) {
			if ( q.empty() ) break;
			now+=2;
			ans-=q.top().first;
			s[q.top().second]='(';
			q.pop();
		}
	}
	if ( now ) puts("-1");
	else printf("%I64d\n%s\n",ans,s);
	return 0;
}