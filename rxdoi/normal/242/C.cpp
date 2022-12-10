#include<map>
#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

int IN()
{
	int c,x;
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

const int N=1e5+19;
struct Point
{
	int x,y;
	bool operator < (const Point& B) const {return x<B.x||x==B.x&&y<B.y;}
};
map<Point,int> M;
int Dx[8]={1,1,1,-1,-1,-1,0,0},Dy[8]={1,0,-1,1,0,-1,1,-1};
int Q[N][2],f,w,Sx,Sy,Tx,Ty,r,a,b,n;

int main()
{
	Sx=IN(),Sy=IN(),Tx=IN(),Ty=IN();
	for (n=IN();n--;)
	{
		r=IN(),a=IN(),b=IN();
		for (int i=a;i<=b;i++) M[(Point){r,i}]=-1;
	}
	M[(Point){Sx,Sy}]=0;
	f=1,w=0;Q[1][0]=Sx,Q[1][1]=Sy;
	while (f>w)
	{
		w++;int x=Q[w][0],y=Q[w][1],D=M[(Point){x,y}];
		For(i,0,8)
		{
			int nx=x+Dx[i],ny=y+Dy[i];Point np=(Point){nx,ny};
			if (nx>=1&&nx<=1e9&&ny>=1&&ny<=1e9&&
				M.count(np)&&M[np]==-1)
				{
					M[np]=D+1,f++,Q[f][0]=nx,Q[f][1]=ny;
					if (nx==Tx&&ny==Ty) return printf("%d\n",D+1),0;
				}
		}
	}
	puts("-1");
}