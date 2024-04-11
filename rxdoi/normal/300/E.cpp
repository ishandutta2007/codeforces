#include<cstdio>
#include<cctype>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
#define Mid (L+R>>1)
using namespace std;

int IN()
{
	int c,x;
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

const int N=1e6+19,top=1e7,Top=top+19;
typedef long long LL;
int A[Top],p[Top],v[Top],ID[Top];
LL tot[Top],L,R,res;
int n,cnt;

bool Check(LL x)
{
	For(i,0,cnt)
	{
		LL num=0;
		for (LL j=x;j;j/=p[i]) num+=j/p[i];
		if (num<tot[i]) return 0;
	}
	return 1;
}

int main()
{
	n=IN();
	For(i,0,n) A[1]++,A[IN()+1]--;
	For(i,1,top+1) A[i]+=A[i-1];
	For(i,2,top+1)
	{
		if (!v[i]) ID[i]=cnt,p[cnt++]=i;
		for (int j=0;j<cnt&&p[j]*i<=top;j++)
		{
			v[p[j]*i]=1;
			if (i%p[j]==0) break;
		}
	}
	For(i,0,cnt)
		for (int j=p[i];j<=top;j+=p[i])
			for (LL k=p[i];j%k==0;k*=p[i]) tot[i]+=A[j];
	L=1,R=1LL<<60;
	while (L<=R)
		if (Check(Mid)) res=Mid,R=Mid-1;else L=Mid+1;
	printf("%I64d\n",res);
}