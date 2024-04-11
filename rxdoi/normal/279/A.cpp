#include<cstdio>
using namespace std;

int x,y,nx,ny,Ans;

int main()
{
	scanf("%d%d",&x,&y);
	for (int i=0;;i++)
	{
		if (nx==x&&ny==y) break;
		int nnx=nx+(i%4==0?1:(i%4==2?-1:0))*(i/2+1);
		int nny=ny+(i%4==1?1:(i%4==3?-1:0))*(i/2+1);
		if (nnx==x&&(nny>=y&&ny<=y||nny<=y&&ny>=y)) break;
		if (nny==y&&(nnx>=x&&nx<=x||nnx<=x&&nx>=x)) break;
		Ans++;nx=nnx;ny=nny;
	}
	printf("%d\n",Ans);
}