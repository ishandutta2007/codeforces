#include<cstdio>
#include<map>
using namespace std;

const int Maxn=1e5+19;
int A[Maxn],n,Len,x,y,fx,fy,cnt;
map<int,int> Map;

inline int In(int x) {return x>=0&&x<=Len;}

int main()
{
	scanf("%d%d%d%d",&n,&Len,&x,&y);
	for (int i=1;i<=n;i++) scanf("%d",&A[i]),Map[A[i]]=1;
	for (int i=1;i<=n;i++)
	{
		if (Map[A[i]-x]) fx=1;
		if (Map[A[i]-y]) fy=1;
	}
	cnt=2-(fx+fy);
	if (cnt==0) puts("0");
		else if (cnt==1)
		{
			puts("1");
			if (!fx) printf("%d\n",x);else printf("%d\n",y);
		} else 
		{
			for (int i=1;i<=n;i++)
			{
				if (Map[A[i]+x-y]&&In(A[i]+x)) {puts("1"),printf("%d\n",A[i]+x);return 0;}
				if (Map[A[i]+y-x]&&In(A[i]+y)) {puts("1"),printf("%d\n",A[i]+y);return 0;}
				if (Map[A[i]-x+y]&&In(A[i]-x)) {puts("1"),printf("%d\n",A[i]-x);return 0;}
				if (Map[A[i]-y+x]&&In(A[i]-y)) {puts("1"),printf("%d\n",A[i]-y);return 0;}
				if (Map[A[i]+x+y]) {puts("1");printf("%d\n",A[i]+x);return 0;}
			}
			puts("2");
			printf("%d %d\n",x,y);
		}
}