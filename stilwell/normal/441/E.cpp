#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#define db double
#define For(i,x,y) for (i=x;i<=y;i++)
using namespace std;
int i,j,k,n,m,u;
db p,f[210][270][250][2],x;
int main() {
	scanf("%d%d%lf",&n,&m,&p);
	p=1.*p/100;
	int A=n&255,B=n/256,C=0;
	if (B&1) {
		For(i,0,40) if (B>>i&1) C++;
		else break;
		f[0][A][C][1]=1;
	} else {
		For(i,0,40) if (!(B>>i&1)) C++;
		else break;
		if (!B) C=0;
		f[0][A][C][0]=1;
	}
	For(i,1,m)For(j,0,255)For(k,0,240)For(u,0,1) if (x=f[i-1][j][k][u]) {
		int a=j*2,b=a/256,c=a&255;
		if (b) {
			if (!u) f[i][c][1][1]+=x*p;
			else f[i][c][k+1][1]+=x*p;
		} else {
			if (!u) f[i][c][k+1][0]+=x*p;
			else f[i][c][1][0]+=x*p;
		}
		
		a=j+1,b=a/256,c=a&255;
		if (b) {
			if (!u) f[i][c][1][1]+=x*(1-p);
			else f[i][c][k][0]+=x*(1-p);
		} else f[i][c][k][u]+=x*(1-p);
	}
	db an=0;
	For(i,0,255)For(j,0,240) {
		For(k,0,7) if (i>>k&1) break;
		an+=f[m][i][j][1]*k;
		if (k==8) an+=f[m][i][j][0]*(k+j);
		else an+=f[m][i][j][0]*k;
	}
	printf("%.11lf\n",an);
	//for(;;);
	return 0;
}