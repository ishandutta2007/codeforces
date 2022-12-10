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

const int N=300+19;
int A[N],cnt[N*N];
int n,t,r,Ans;

void Light(int L,int R) {For(i,L,R+1) cnt[i]++;Ans++;}

int main()
{
	scanf("%d%d%d",&n,&t,&r);
	if (t<r) return puts("-1"),0;
	For(i,1,n+1) A[i]=IN();
	sort(A+1,A+n+1);
	For(i,1,n+1)
		for (int j=A[i];cnt[A[i]]<r;j--) Light(max(j,0),j+t-1);
	printf("%d\n",Ans);
}