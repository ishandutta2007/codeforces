// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 20
using namespace std;
struct G {
	int num[4],a,b;
	void read() { scanf("%1d%1d%1d%1d %d %d",num+0,num+1,num+2,num+3,&a,&b); }
	bool chk( int now[4] ) {
		int aa=0,bb=0,i,j;
		for ( i=0; i<4; i++ )
			for ( j=0; j<4; j++ )
				if ( num[i]==now[j] ) {
					if ( i==j ) aa++;
					else bb++;
				}
		return a==aa && b==bb;
	}
} g[N];
bool chk( int n, int x ) {
	char s[5];
	sprintf(s,"%04d",x);
	for ( int i=0; i<4; i++ )
		for ( int j=i+1; j<4; j++ )
			if ( s[i]==s[j] ) return 0;
	int now[4],i;
	for ( i=0; i<4; i++ ) now[i]=s[i]-'0';
	for ( i=0; i<n; i++ ) {
		if ( !g[i].chk(now) ) return 0;
	}
	return 1;
}
int main()
{
	int n,i,cnt=0,ans=-1;
	scanf("%d",&n);
	for ( i=0; i<n; i++ ) g[i].read();
	for ( i=0; i<10000; i++ )
		if ( chk(n,i) ) {
			cnt++;
			ans=i;
		}
	if ( cnt==0 ) puts("Incorrect data");
	else if ( cnt>1 ) puts("Need more data");
	else printf("%04d\n",ans);
	return 0;
}