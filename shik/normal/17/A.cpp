// by shik
#include <cstdio>
int ps[1000]={2},pk=1,p[1010];
void make_p() {
	int i,j;
	for ( i=3; i<=33; i+=2 )
		if ( !p[i] )
			for ( j=i*i; j<=1000; j+=i+i )
				p[j]=1;
	for ( i=3; i<=1000; i+=2 )
		if ( !p[i] ) ps[pk++]=i;
}
bool chk( int x ) {
	if ( x%2==0 || p[x] ) return 0;
	int i;
	for ( i=0; i<pk-1&&ps[i]<x; i++ ) {
		//printf("%d+%d+%d vs %d\n",ps[i],ps[i+1],1,x);
		if ( ps[i]+ps[i+1]+1==x ) return 1;
	}
	return 0;
}
int main()
{
	make_p();
	int n,k,cnt=0,i;
	scanf("%d%d",&n,&k);
	for ( i=2; i<=n; i++ )
		if ( chk(i) ) cnt++;
	if ( cnt>=k ) puts("YES");
	else puts("NO");
	return 0;
}