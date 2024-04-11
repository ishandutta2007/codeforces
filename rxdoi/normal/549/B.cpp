#include<cstdio>
#include<vector>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

const int N=100+19;
char s[N][N];
int A[N],B[N],n;
vector<int> V;

int main()
{
	scanf("%d",&n);
	For(i,1,n+1) scanf("%s",s[i]+1);
	For(i,1,n+1) scanf("%d",&A[i]);
	for (;;)
	{
		int x=-1;
		For(i,1,n+1) if (A[i]==B[i]) {x=i;break;}
		if (x==-1) break;
		For(i,1,n+1) if (s[x][i]=='1') B[i]++;
		V.push_back(x);
	}
	printf("%d\n",V.size());
	For(i,0,V.size()) printf("%d ",V[i]);
}