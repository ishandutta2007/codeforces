// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1010
#define FRONT 1
#define BACK 2
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int q;
struct S {
	int op,c,t;
	bool read( int flg ) {
		if ( flg ) {
			q=getchar();
			if ( q==EOF || q=='\n' || q==' ' ) return 0;
			if ( q!='+' && q!='-' ) {
				printf("q=(%d,%c)\n",q,q);
				char ss[100000];
				gets(ss);
				puts(ss);
			}
			op=q=='-'?-1:1;
		} else op=1;
		q=getchar();
		if ( q<'0' || q>'9' ) {
			c=1; getchar();
		} else {
			ungetc(q,stdin);
			scanf("%d",&c);
			getchar(); getchar(); getchar();
		}
		q=getchar();
		if ( q!='+' && q!='a' ) printf("q=%d,%c,",q,q);
		if ( q=='+' ) t=BACK;
		else t=FRONT;
		return 1;
	}
	int eval( int &x ) {
		if ( t==BACK ) return op*c*x++;
		else return op*c*++x;
	}
} s[N];
int tmt;
bool cp( S a, S b ) {
	if ( a.op!=b.op ) return a.op<b.op;
	return a.op*a.c<b.op*b.c;
	int x=tmt,y=tmt,sx=0,sy=0;
	sx+=a.eval(x); sx+=b.eval(x);
	sy+=b.eval(y); sy+=a.eval(y);
	return sx>sy;
}
int main()
{
	int a,n=0,ans=0;
	scanf("%d",&a); tmt=a; while ( getchar()!='\n' );
	while ( s[n].read(n) ) n++;
	sort(s,s+n,cp);
	for ( int i=0; i<514; i++ ) for ( int j=1; j<n; j++ ) if ( !cp(s[j-1],s[j]) ) swap(s[j-1],s[j]);
	for ( int i=0; i<n; i++ ) for ( int j=0; j<i; j++ ) if ( cp(s[i],s[j]) ) swap(s[i],s[j]);
	for ( int i=0; i<n; i++ ) {
		//printf("(%d,%d,%d)\n",s[i].op,s[i].c,s[i].t);
		ans+=s[i].eval(a);
	}
	printf("%d\n",ans);
	return 0;
}