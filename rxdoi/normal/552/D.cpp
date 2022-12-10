 #include<cstdio>
#include<cstring>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

const int Top=500,N=2000+19;
struct Point {int x,y;} P[N];
int f[Top][Top],T[Top][Top],n,x,y;
long long tmp,Ans;

int gcd(int a,int b) {return !b?a:gcd(b,a%b);}

int main()
{
	scanf("%d",&n);
	For(i,0,n) scanf("%d%d",&x,&y),P[i]=(Point){x+100,y+100};
	//[0,200]
	Ans=1LL*n*(n-1)*(n-2)/6;
	For(i,0,n) For(j,0,n)
		if (i!=j)
		{
			int t=abs(gcd(P[j].x-P[i].x,P[j].y-P[i].y));
			int nx=(P[j].x-P[i].x)/t,ny=(P[j].y-P[i].y)/t;
			if (nx<0||nx==0&&ny<0) nx=-nx,ny=-ny;
			int &h=f[P[i].x+nx][P[i].y+ny];
			if (T[P[i].x+nx][P[i].y+ny]!=i+1) T[P[i].x+nx][P[i].y+ny]=i+1,h=0;
			tmp+=(h++);
		}
	Ans-=tmp/3;
	printf("%I64d\n",Ans);
}