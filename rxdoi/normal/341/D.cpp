#include<cstdio>
#include<cctype>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

const int N=1000+19;
typedef long long LL;
int n,Q,a,b,c,d,opt;LL v;

LL IN()
{
	int c;LL x;
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

struct BIT_2D
{
	LL C[N][N];

	void Update(int x,int y,int v)
	{
		for (int i=x;i<=n;i+=i&-i)
			for (int j=y;j<=n;j+=j&-j) C[i][j]^=v;
	}
	int Query(int x,int y)
	{
		int Ans=0;
		for (int i=x;i;i-=i&-i)
			for (int j=y;j;j-=j&-j) Ans^=C[i][j];
		return Ans;
	}
} T[4];

void Modify(int a,int b,LL v)
{
	if (a&1&&b&1) T[0].Update(a,b,v);
	if (b&1) T[1].Update(a,b,v);
	if (a&1) T[2].Update(a,b,v);
	T[3].Update(a,b,v);
}
LL Count(int a,int b)
{
	LL res=0;
	res^=T[0].Query(a,b);
	if (a+1&1) res^=T[1].Query(a,b);
	if (b+1&1) res^=T[2].Query(a,b);
	if (a+1&1&&b+1&1) res^=T[3].Query(a,b);
	return res;
}

int main()
{
	for (n=IN(),Q=IN();Q--;)
	{
		opt=IN(),a=IN(),b=IN(),c=IN(),d=IN();
		if (opt==1) printf("%I64d\n",Count(c,d)^Count(c,b-1)^Count(a-1,d)^Count(a-1,b-1));
			else v=IN(),Modify(a,b,v),Modify(a,d+1,v),Modify(c+1,b,v),Modify(c+1,d+1,v);
	}
}