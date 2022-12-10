#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

const int N=2000+19,oo=(1<<30)-1,Len=12000000;
struct Point {int x,y;} Q[N*N],T[9];
int Dx[4]={1,0,-1,0},Dy[4]={0,1,0,-1};
int s[N][N],t[N][N],n,C1,C2;
char Buf[Len],*B=Buf;

int IN()
{
	int c,x;
	while (!isdigit(c=*B++));x=c-'0';
	while (isdigit(c=*B++)) x=(x<<1)+(x<<3)+c-'0';return x;
}

int sqr(int x) {return x*x;}
void BFS(int Sx,int Sy)
{
	int f=1,w=0,D=0,x,y;
	Q[1]=(Point){Sx,Sy};t[Sx][Sy]=0;
	while (f>w)
	{
		Point A=Q[++w];
		For(i,0,4) if (t[x=A.x+Dx[i]][y=A.y+Dy[i]]) t[x][y]=0,Q[++f]=(Point){x,y};
	}
	if (f<60) return;
	T[1]=T[2]=T[3]=T[4]=(Point){oo,oo};
	T[5]=T[6]=T[7]=T[8]=(Point){-oo,-oo};
	For(i,1,f+1)
	{
		if (Q[i].x<T[1].x||Q[i].x==T[1].x&&Q[i].y<T[1].y) T[1]=Q[i];
		if (Q[i].x<T[2].x||Q[i].x==T[2].x&&Q[i].y>T[2].y) T[2]=Q[i];
		if (Q[i].y<T[3].y||Q[i].y==T[3].x&&Q[i].x<T[3].x) T[3]=Q[i];
		if (Q[i].y<T[4].y||Q[i].y==T[4].x&&Q[i].x>T[4].x) T[4]=Q[i];
		if (Q[i].x>T[5].x||Q[i].x==T[5].x&&Q[i].y<T[5].y) T[5]=Q[i];
		if (Q[i].x>T[6].x||Q[i].x==T[6].x&&Q[i].y>T[6].y) T[6]=Q[i];
		if (Q[i].y>T[7].y||Q[i].y==T[7].x&&Q[i].x<T[7].x) T[7]=Q[i];
		if (Q[i].y>T[8].y||Q[i].y==T[8].x&&Q[i].x>T[8].x) T[8]=Q[i];
	}
	For(i,1,9) For(j,1,9) D=max(D,sqr(T[i].x-T[j].x)+sqr(T[i].y-T[j].y));
	if (1.0*f/D>0.618) C1++;else C2++;
}

int main()
{
	fread(Buf,1,Len,stdin);
	n=IN();
	For(i,1,n+1) For(j,1,n+1) s[i][j]=IN();

	For(i,1,n+1) For(j,1,n+1)
	{
		int c=0;
		For(k,0,4) if (s[i+Dx[k]][j+Dy[k]]) c++;
		t[i][j]=(s[i][j]||c>=3);
	}

	For(i,1,n+1) For(j,1,n+1) if (t[i][j]) BFS(i,j);
	printf("%d %d\n",C1,C2);
}