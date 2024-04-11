// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
map<string,int> cnt;
int main()
{
	int n,i,w=0;
	char s[110][20];
	scanf("%d",&n);
	for ( i=0; i<n; i++ ) scanf("%s",s[i]);
	for ( i=0; i<n; i++ ) cnt[s[i]]++;
	for ( i=0; i<n; i++ )
		if ( cnt[s[i]]>cnt[s[w]] ) w=i;
	puts(s[w]);
	return 0;
}