#include<cmath>
#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

int IN()
{
	int c,x,f;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=1e5+19;
struct Event {int x,y,k;} S[N];
int A[N],B[N],Fa[N];
int n,Q,Sz,top,x,Ans;

int Getf(int x) {return Fa[x]==x?x:Fa[x]=Getf(Fa[x]);}

int main()
{
	n=IN(),Q=IN(),Sz=sqrt(n)+1;
	For(i,1,n+1) A[i]=IN();
	For(i,1,n+1) B[i]=IN();
	while (Q--)
		if (IN()==1)
		{
			S[++top]=(Event){IN(),IN(),IN()};
			if (top==Sz)
			{
				For(i,1,n+2) Fa[i]=i;
				for (int i=top;i;i--)
					for (int j=Getf(S[i].y);j<S[i].y+S[i].k;j=Getf(j+1)) B[j]=A[S[i].x+(j-S[i].y)],Fa[j]=j+1;
				top=0;
			}
		} else
		{
			Ans=B[x=IN()];
			for (int i=top;i;i--)
				if (S[i].y<=x&&x<S[i].y+S[i].k) {Ans=A[S[i].x+(x-S[i].y)];break;}
			printf("%d\n",Ans);
		}
}