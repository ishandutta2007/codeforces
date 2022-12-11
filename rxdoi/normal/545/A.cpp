#include<cstdio>
#include<cctype>
#include<vector>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

int IN()
{
	int c,x;
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

vector<int> V;
int n,x;

int main()
{
	scanf("%d",&n);
	For(i,1,n+1)
	{
		int f=1;
		For(j,1,n+1)
		{
			scanf("%d",&x);
			if (x==1||x==3) f=0;
		}
		if (f) V.push_back(i);
	}
	printf("%d\n",V.size());
	For(i,0,V.size()) printf("%d ",V[i]);puts("");
}