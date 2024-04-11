// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100010
using namespace std;
char s[N];
int main()
{
	int k,cnt[26]={},bye[26]={},ans=26;
	scanf("%s %d",s,&k);
	for ( int i=0; s[i]; i++ ) cnt[s[i]-'a']++;
	while ( 1 ) {
		int w=-1;
		for ( int i=0; i<26; i++ )
			if ( !bye[i] && (w==-1||cnt[i]<cnt[w]) ) w=i;
		if ( w==-1 || cnt[w]>k ) break;
		bye[w]=1;
		k-=cnt[w];
		ans--;
	}
	printf("%d\n",ans);
	for ( int i=0; s[i]; i++ )
		if ( !bye[s[i]-'a'] ) putchar(s[i]);
	puts("");
	return 0;
}