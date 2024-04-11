// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	char s[1010];
	int n=strlen(gets(s)),p[1010]={},cnt[130]={};
	for ( int i=0; i<n; i++ ) cnt[(int)s[i]]++;
	for ( int i=2; i<=n; i++ ) if ( !p[i] ) for ( int j=i+i; j<=n; j+=i ) p[j]=1;
	int w=max_element(cnt,cnt+130)-cnt,tmt=0;
	for ( int i=2; i<=n; i++ ) if ( p[i] || 2*i<=n ) tmt++;
	if ( tmt>cnt[w] ) { puts("NO"); return 0; }
	puts("YES");
	for ( int i=1; i<=n; i++ ) {
		if ( i>1 && (p[i] || 2*i<=n) ) putchar(w),cnt[w]--;
		else {
			int flg=0;
			for ( int j='a'; j<='z'; j++ ) if ( j!=w && cnt[j]>0 ) { putchar(j); cnt[j]--; flg=1; break; }
			if ( !flg ) putchar(w);
		}
	}
	return 0;
}