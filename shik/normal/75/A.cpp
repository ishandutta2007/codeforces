// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int a,b,c,i,j;
	char sa[20],sb[20],sc[20];
	scanf("%d%d",&a,&b);
	c=a+b;
	sprintf(sa,"%d",a);
	sprintf(sb,"%d",b);
	sprintf(sc,"%d",c);
	for ( i=j=0; sa[i]; i++ )
		if ( sa[i]!='0' ) sa[j++]=sa[i];
	sa[j]=0;
	for ( i=j=0; sb[i]; i++ )
		if ( sb[i]!='0' ) sb[j++]=sb[i];
	sb[j]=0;
	for ( i=j=0; sc[i]; i++ )
		if ( sc[i]!='0' ) sc[j++]=sc[i];
	sc[j]=0;
	puts(atoi(sa)+atoi(sb)==atoi(sc) ? "YES" : "NO" );
	return 0;
}