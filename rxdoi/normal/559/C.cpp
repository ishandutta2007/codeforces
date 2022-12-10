#include<cstdio>
#include<cctype>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

int IN()
{
	int c,x;
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

const int N=2000+19,Top=200000,P=1e9+7;
struct Point
{
	int x,y;
	bool operator < (const Point& B) const {return x<B.x||x==B.x&&y<B.y;}
} A[N];
int F[N],Fac[Top+1],Inv[Top+1],h,w,n,Ans;

int Pow(int a,int b)
{
	int res=1;
	for (;b;b>>=1,a=1LL*a*a%P) if (b&1) res=1LL*res*a%P;
	return res;
}
int C(int n,int m) {return 1LL*Fac[n]*Inv[m]%P*Inv[n-m]%P;}
int D(int n,int m) {return C(n+m-2,n-1);}

int main()
{
	h=IN(),w=IN(),n=IN();
	For(i,0,n) A[i]=(Point){IN(),IN()};A[n++]=(Point){h,w};
	sort(A,A+n);
	Fac[0]=1;For(i,1,Top+1) Fac[i]=1LL*i*Fac[i-1]%P;
	Inv[Top]=Pow(Fac[Top],P-2);
	for (int i=Top-1;~i;i--) Inv[i]=1LL*Inv[i+1]*(i+1)%P;
	For(i,0,n)
	{
		F[i]=D(A[i].x,A[i].y);
		For(j,0,i)
			if (A[j].x<=A[i].x&&A[j].y<=A[i].y)
				F[i]=(F[i]-1LL*F[j]*D(A[i].x-A[j].x+1,A[i].y-A[j].y+1)%P+P)%P;
	}
	printf("%d\n",F[n-1]);
}