// by shik
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int n,h[110],m[110],i,ans=1,cnt=1; char ch;
	scanf("%d",&n);
	for ( i=0; i<n; i++ ) {
		scanf(" [%d:%d %c.m.]%*[^\n]",h+i,m+i,&ch);
		if ( ch=='p' && h[i]==24 ) {
			h[i]=0; continue;	
		}
		h[i]%=12;
		if ( ch=='p' ) h[i]+=12;
	}
	for ( i=1; i<n; i++ ) {
		if ( h[i]*60+m[i]<h[i-1]*60+m[i-1] ) {
			ans++;
			cnt=1;	
		}
		if ( h[i]*60+m[i]>h[i-1]*60+m[i-1] ) cnt=1;
		if ( h[i]*60+m[i]==h[i-1]*60+m[i-1] ) cnt++;
		if ( cnt>10 ) { ans++; cnt=1; }
	}
	printf("%d\n",ans);
	return 0;
}