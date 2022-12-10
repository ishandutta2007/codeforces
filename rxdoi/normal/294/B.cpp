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

const int N=100+19;
int A[N],B[N],n,t,w,tmp,tmp2,Ans=(1<<30)-1;

int main()
{
	n=IN();
	For(i,0,n) IN()==1?A[++*A]=IN():B[++*B]=IN();
	sort(A+1,A+*A+1);
	sort(B+1,B+*B+1);
	For(i,0,*A+1)
	{
		tmp+=i?A[i]:0;tmp2=tmp;
		For(j,0,*B+1)
		{
			tmp2+=j?B[j]:0;
			if (tmp2<=(*A-i)+2*(*B-j)) Ans=min(Ans,(*A-i)+2*(*B-j));
		}
	}
	printf("%d\n",Ans);
}