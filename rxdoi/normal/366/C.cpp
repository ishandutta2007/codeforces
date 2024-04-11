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

const int N=100+19,Z=2000000;
int A[N],v[N],f[2*Z];
int n,k,L,R;

int main()
{
	n=IN(),k=IN();
	For(i,1,n+1) v[i]=IN();
	For(i,1,n+1) A[i]=v[i]-IN()*k;
	memset(f,200,sizeof(f));
	f[Z]=0;L=R=Z;
	For(i,1,n+1)
	{
		L=min(L,L+A[i]),R=max(R,R+A[i]);
		if (A[i]>=0)
			for (int j=R;j>=L;j--) f[j]=max(f[j],f[j-A[i]]+v[i]);
		else 
			for (int j=L;j<=R;j++) f[j]=max(f[j],f[j-A[i]]+v[i]);
	}
	printf("%d\n",!f[Z]?-1:f[Z]);
}