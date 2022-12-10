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

const int N=1e5+19,Top=1e5;
int A[N],C[N],f[N],g[N],Ans[N];
int n,Max;
map<int,int> M;

void Update(int x,int v) {for (;x<=Top;x+=x&-x) C[x]=max(C[x],v);}
int Query(int x) {int Ans=0;for (;x;x-=x&-x) Ans=max(Ans,C[x]);return Ans;}

int main()
{
	n=IN();
	For(i,1,n+1) A[i]=IN();
	For(i,1,n+1) f[i]=Query(A[i]-1)+1,Update(A[i],f[i]),Max=max(Max,f[i]);
	memset(C,0,sizeof(C));
	for (int i=n;i;i--) g[i]=Query(Top-A[i])+1,Update(Top-A[i]+1,g[i]);
	For(i,1,n+1) if (f[i]+g[i]-1!=Max) Ans[i]=1;else M[f[i]]++;
	For(i,1,n+1) if (f[i]+g[i]-1==Max) Ans[i]=M[f[i]]>1?2:3;
	For(i,1,n+1) printf("%d",Ans[i]);puts("");
}