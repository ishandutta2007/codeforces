// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int get() {
	char s[20];
	scanf("%s",s);
	if ( s[0]==s[1] && s[0]==s[3] && s[0]==s[4] && s[0]==s[6] && s[0]==s[7] ) return 0;
	if ( s[0]>s[1] && s[1]>s[3] && s[3]>s[4] && s[4]>s[6] && s[6]>s[7] ) return 1;
	return 2;
}
struct F {
	int cnt[3];
	char name[30];
	void read() {
		int n;
		scanf("%d %s",&n,name);
		memset(cnt,0,sizeof(cnt));
		while ( n-- ) cnt[get()]++;
	}
} f[110];
const char str[3][100]={
	"If you want to call a taxi, you should call:",
	"If you want to order a pizza, you should call:",
	"If you want to go to a cafe with a wonderful girl, you should call:"
};
int main()
{
	int n,mx[3]={};
	scanf("%d",&n);
	for ( int i=0; i<n; i++ ) f[i].read();
	for ( int i=0; i<n; i++ ) for ( int j=0; j<3; j++ ) mx[j]=max(mx[j],f[i].cnt[j]);
	for ( int i=0; i<3; i++ ) {
		printf("%s",str[i]);
		for ( int j=0,k=0; j<n; j++ ) if ( mx[i]==f[j].cnt[i] ) {
			if ( k++ ) putchar(',');
			printf(" %s",f[j].name);
		}
		puts(".");
	}
	return 0;
}