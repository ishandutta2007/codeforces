// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define N 2010
#define H 131
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;
char s[N],st[N],ed[N];
bool gs[N],ge[N];
vector<LL> sol;
LL sh[N],pw[N]={1};
LL get( int l, int r ) { return sh[r]-sh[l-1]*pw[r-l+1]; }
int main()
{
	for ( int i=1; i<N; i++ ) pw[i]=pw[i-1]*H; 
	scanf("%s %s %s",s+1,st,ed);
	int n=strlen(s+1),ls=strlen(st),le=strlen(ed);
	for ( int i=1; i<=n; i++ ) sh[i]=sh[i-1]*H+s[i];
	for ( int i=1; i+ls-1<=n; i++ ) if ( strncmp(s+i,st,ls)==0 ) gs[i]=1;
	for ( int i=1; i+le-1<=n; i++ ) if ( strncmp(s+i,ed,le)==0 ) ge[i]=1;
	for ( int i=1; i<=n; i++ ) for ( int j=i; j<=n; j++ ) if ( i+ls<=j+le && gs[i] && ge[j] ) sol.push_back(get(i,j+le-1));
	sort(sol.begin(),sol.end());
	printf("%d\n",(int)(unique(sol.begin(),sol.end())-sol.begin()));
	return 0;
}