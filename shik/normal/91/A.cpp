// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[20010],t[1000010];
int nxt[20010][26];
int main()
{
	int n=strlen(gets(s));
	int m=strlen(gets(t));
	int app[26]={};
	for ( int i=0; s[i]; i++ ) app[s[i]-'a']++;
	for ( int i=0; t[i]; i++ )
		if ( !app[t[i]-'a'] ) {
			puts("-1");
			return 0;
		}
	for ( int i=0; i<n; i++ ) s[i+n]=s[i];
	for ( int i=0; i<26; i++ ) nxt[n+n][i]=-1;
	for ( int i=n+n-1; i>=0; i-- ) {
		for ( int j=0; j<26; j++ ) nxt[i][j]=nxt[i+1][j];
		nxt[i][s[i]-'a']=i;
	}
	int ans=1;
	for ( int i=0,j=-1; i<m; i++ ) {
		if ( nxt[j+1][t[i]-'a']>=n ) ans++;
		j=nxt[j+1][t[i]-'a']%n;
	}
	printf("%d\n",ans);
	return 0;
}