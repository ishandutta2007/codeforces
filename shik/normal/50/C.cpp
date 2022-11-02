// by shik
#include <cstdio>
#include <algorithm>
#define N 500010
using namespace std;
struct P {
	int x,y;
	P(){}
	P( int _x, int _y ):x(_x),y(_y){}
} p[N];
int main()
{
	int i,n,m=0,x,y,L,R,U,D,LU,UR,RD,DL,ans=0;
	scanf("%d",&n);
	while ( n-- ) {
		scanf("%d%d",&x,&y);
		p[m]=P(x-1,y); m++;
		p[m]=P(x+1,y); m++;
		p[m]=P(x,y-1); m++;
		p[m]=P(x,y+1); m++;
	}
	n=m;
	L=R=p[0].x;
	U=D=p[0].y;
	LU=RD=p[0].x-p[0].y;
	UR=DL=p[0].x+p[0].y;
	for ( i=0; i<n; i++ ) {
		L=min(L,p[i].x);
		R=max(R,p[i].x);
		D=min(D,p[i].y);
		U=max(U,p[i].y);	
		LU=min(LU,p[i].x-p[i].y);
		UR=max(UR,p[i].x+p[i].y);
		RD=max(RD,p[i].x-p[i].y);
		DL=min(DL,p[i].x+p[i].y);
	}
	ans=2*(R-L)+2*(U-D);
	ans-=U+LU-L;
	ans-=R-RD-D;
	ans-=U-UR+R;
	ans-=DL-L-D;
	printf("%d\n",ans);
	return 0;
}