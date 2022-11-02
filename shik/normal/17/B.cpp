// by shik
#include <cstdio>
#include <cstring>
int main()
{
	int n,m,i,a,b,c,sml[1010],ans=0,cnt=0;
	scanf("%d",&n);
	for ( i=0; i<n; i++ ) scanf("%*d");
	memset(sml,-1,sizeof(sml));
	scanf("%d",&m);
	while ( m-- ) {
		scanf("%d%d%d",&a,&b,&c);
		if ( sml[b]==-1 || c<sml[b] ) sml[b]=c;
	}
	for ( i=1; i<=n; i++ )
		if ( sml[i]==-1 ) cnt++;
		else ans+=sml[i];
	if ( cnt>1 ) puts("-1");
	else printf("%d\n",ans);
	return 0;
}