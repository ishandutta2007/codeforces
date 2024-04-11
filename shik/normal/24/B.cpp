// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#define N 50
using namespace std;
const int tbl[10]={25, 18, 15, 12, 10, 8, 6, 4, 2, 1};
struct P {
	char name[100];
	int pt,cnt[50];
} p[N];
map<string,int> idx;
bool cp1( P a, P b ) {
	if ( a.pt!=b.pt ) return a.pt>b.pt;
	for ( int i=0; i<50; i++ )
		if ( a.cnt[i]!=b.cnt[i] ) return a.cnt[i]>b.cnt[i];
	return 0;
}
bool cp2( P a, P b ) {
	if ( a.cnt[0]!=b.cnt[0] ) return a.cnt[0]>b.cnt[0];
	if ( a.pt!=b.pt ) return a.pt>b.pt;
	for ( int i=0; i<50; i++ )
		if ( a.cnt[i]!=b.cnt[i] ) return a.cnt[i]>b.cnt[i];
	return 0;
}
int main()
{
	int t,m,n=0; char s[100];
	scanf("%d",&t);
	while ( t-- ) {
		scanf("%d",&m);
		for ( int i=0; i<m; i++ ) {
			scanf("%s",s);
			if ( !idx.count(s) ) {
				strcpy(p[n].name,s);
				idx[s]=n++;
			}
			if ( i<10 ) p[idx[s]].pt+=tbl[i];
			p[idx[s]].cnt[i]++;
		}
	}
	sort(p,p+n,cp1); puts(p[0].name);
	sort(p,p+n,cp2); puts(p[0].name);
	return 0;
}