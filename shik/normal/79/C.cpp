// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100010
using namespace std;
char s[N],b[20][20];
int tmt[N];
void proc( char *t ) {
	int i,m=strlen(t);
	for ( i=0; s[i]; i++ )
		if ( strncmp(s+i,t,m)==0 ) tmt[i+m-1]=max(tmt[i+m-1],i);
}
int main()
{
	memset(tmt,-1,sizeof(tmt));
	int n,i,j,len=-1,st=-1;
	gets(s);
	scanf("%d",&n);
	for ( i=0; i<n; i++ ) scanf("%s",b[i]);
	for ( i=0; i<n; i++ ) proc(b[i]);
	for ( i=j=0; s[i]; i++ ) {
		//printf("%d: %d\n",i,tmt[i]);
		j=max(j,tmt[i]+1);
		if ( i-j+1>len ) {
			len=i-j+1;
			st=j;	
		}
	}
	if ( len==0 ) st=0;
	printf("%d %d\n",len,st);
	return 0;
}