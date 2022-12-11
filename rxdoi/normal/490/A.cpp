#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> A[3];
int n,x;

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&x),A[x-1].push_back(i);
	int Ans=min(A[0].size(),min(A[1].size(),A[2].size()));
	printf("%d\n",Ans);
	for (int i=0;i<Ans;i++) printf("%d %d %d\n",A[0][i],A[1][i],A[2][i]);
}