#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;

const int Maxn=1e5+19;
map<int,int> Map;
int A[Maxn],x,n,Ans,k;

int main()
{
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++) scanf("%d",&A[i]);
	sort(A,A+n);
	for (int i=0;i<n;i++)
		if (A[i]%k!=0||A[i]%k==0&&!Map[A[i]/k]) Map[A[i]]=1,Ans++;
	printf("%d\n",Ans);
}