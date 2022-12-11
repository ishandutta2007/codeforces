#include<cstdio>
#include<cstring>
using namespace std;

const int Maxn=200000+19;
typedef int one[Maxn];
one A,B,cntA,cntB,Ans,C;
int n;

int Query(int x) {int Ans=0;while (x) Ans+=C[x],x-=x&-x;return Ans;}
int kthMin(int x) {int Ans=x;x--;while (x) {Ans-=C[x],x-=x&-x;} return Ans;}
void Add(int x) {while (x<=n) C[x]++,x+=x&-x;}
void Del(int x) {while (x<=n) C[x]--,x+=x&-x;}
void getIdx(int *A,int *B)
{
	memset(C,0,sizeof(C));
	for (int i=1;i<=n;i++) B[i+1]=kthMin(A[i])-1,Add(A[i]);
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&A[i]),A[i]++;
	for (int i=1;i<=n;i++) scanf("%d",&B[i]),B[i]++;
	getIdx(A,cntA);
	getIdx(B,cntB);
	for (int i=n;i>=1;i--) 
	{
		Ans[i]+=cntA[i]+cntB[i];
		Ans[i-1]+=Ans[i]/(n-i+2),Ans[i]%=n-i+2;
	}
	memset(C,0,sizeof(C));
	for (int i=1;i<=n;i++) Add(i);
	for (int i=2;i<=n+1;i++)
	{
		int L=1,R=n,res;
		while (L<=R)
		{
			int Mid=(L+R)>>1;
			if (Query(Mid-1)<=Ans[i]) res=Mid,L=Mid+1;else R=Mid-1;
		}
		Del(res);printf("%d ",res-1);
	}
	puts("");
}