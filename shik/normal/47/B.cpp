// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int cnt[3],ord[3]={0,1,2};
bool cp( int a, int b ) { return cnt[a]<cnt[b]; }
int main()
{
	char x,op,y;
	for ( int i=0; i<3; i++ ) {
		scanf(" %c%c%c",&x,&op,&y);
		if ( op=='>' ) cnt[x-'A']++;
		else cnt[y-'A']++;
	}
	sort(ord,ord+3,cp);
	if ( cnt[ord[0]]!=0 ) printf("Impossible");
	else for ( int i=0; i<3; i++ ) putchar('A'+ord[i]);
	puts("");
	return 0;
}