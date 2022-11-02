// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <string>
#include <functional>
#define N 110
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int p[N];
map<string,int> app;
int main()
{
	int n,m;
	char s[100];
	scanf("%d%d",&n,&m);
	for ( int i=0; i<n; i++ ) scanf("%d",p+i);
	while ( m-- ) {
		scanf("%s",s);
		app[s]++;
	}
	int lst[N],nl=0;
	FOR(it,app) lst[nl++]=it->second;
	int a=0,b=0;
	sort(p,p+n);
	sort(lst,lst+nl,greater<int>());
	for ( int i=0; i<nl; i++ ) a+=lst[i]*p[i];
	sort(p,p+n,greater<int>());
	for ( int i=0; i<nl; i++ ) b+=lst[i]*p[i];
	printf("%d %d\n",a,b);
	return 0;
}