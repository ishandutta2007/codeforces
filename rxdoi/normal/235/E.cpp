#include<map>
#include<cstdio>
#include<cstring>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

const int N=2000+19,oo=(1<<30)-1;
typedef unsigned int Uint;
typedef long long LL;
map<LL,Uint> M[N];
int p[N],v[N],a,b,c,cnt;

Uint DFS(int a,int b,int c,int x)
{
	if (a>b) swap(a,b);
	if (b>c) swap(b,c);
	if (a>b) swap(a,b);
	if (c==1) return 1;
	if (x==0) return 1;
	LL A=a*N*N+b*N+c;Uint res=0;
	if (M[x].count(A)) return M[x][A];
	for (int i=a,c1=0;i;i/=p[x],c1++)
		for (int j=b,c2=0;j;j/=p[x],c2++)
			for (int k=c,c3=0;k;k/=p[x],c3++)
				res+=DFS(i,j,k,x-1)*(c1+c2+c3+1);
	return M[x][A]=res;
}

int main()
{
	scanf("%d%d%d",&a,&b,&c);
	For(i,2,N)
		if (!v[i])
		{
			p[++*p]=i;
			for (int j=i*i;j<N;j+=i) v[j]=1;
		}
	printf("%d\n",DFS(a,b,c,*p)&oo);
}