#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

const int Maxn=100+19;
int A[Maxn],B[Maxn];
int n,m,tmp;
long long Ans=0;
vector<int> C;

long long Max(long long A,long long B) {return A>B?A:B;}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) scanf("%d",&A[i]);
	for (int i=0;i<m;i++) {scanf("%d",&tmp);B[tmp-1]=1;}
	for (int i=0;i<n;i++) if (!B[i]) Ans+=A[i];else C.push_back(A[i]);
	sort(C.begin(),C.end());
	for (int i=C.size()-1;i>=0;i--) Ans+=Max(Ans,C[i]);
	printf("%I64d\n",Ans);
	return 0;
}