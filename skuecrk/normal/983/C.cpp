#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 2000
#define K 715
int f[10][10][10][10],A[K+5],B[K+5],C[K+5],D[K+5],cnt,F[MN+5][K+5][10];
int get(int a,int b,int c,int d)
{
	int u[4];
	u[0]=a;u[1]=b;u[2]=c;u[3]=d;
	sort(u,u+4);
	return f[u[0]][u[1]][u[2]][u[3]];
}
inline void rw(int&x,int y){if(y<x)x=y;}
int main()
{
	int n=read(),i,j,k,a,b,c,d,x,y;
	for(a=0;a<10;++a)for(b=a;b<10;++b)for(c=b;c<10;++c)for(d=c;d<10;++d)
		f[a][b][c][d]=++cnt,A[cnt]=a,B[cnt]=b,C[cnt]=c,D[cnt]=d;
	memset(F,40,sizeof(F));F[0][1][1]=0;
	for(i=1;i<=n;++i)
	{
		x=read();y=read();
		for(j=1;!A[j];++j)for(k=1;k<=9;++k)if(F[i-1][j][k]<F[0][0][0])
			rw(F[i][get(y,B[j],C[j],D[j])][x],F[i-1][j][k]+abs(x-k)+1);
		for(j=cnt;j;--j)for(k=1;k<=9;++k)if(F[i][j][k]<F[0][0][0])
		{
			if(A[j])rw(F[i][get(0,B[j],C[j],D[j])][A[j]],F[i][j][k]+abs(k-A[j])+1);
			if(B[j])rw(F[i][get(A[j],0,C[j],D[j])][B[j]],F[i][j][k]+abs(k-B[j])+1);
			if(C[j])rw(F[i][get(A[j],B[j],0,D[j])][C[j]],F[i][j][k]+abs(k-C[j])+1);
			if(D[j])rw(F[i][get(A[j],B[j],C[j],0)][D[j]],F[i][j][k]+abs(k-D[j])+1);
		}
	}
	for(i=1;i<=9;++i)rw(F[0][0][0],F[n][1][i]);
	printf("%d",F[0][0][0]);
}