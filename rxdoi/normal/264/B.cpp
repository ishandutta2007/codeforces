#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

const int Maxn=1e5+19;
int A,F[Maxn];
int is_p[Maxn],p[Maxn];
int n,cnt,E_cnt,Ans;

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) 
	{
		scanf("%d",&A);
		vector<int> tmp;
		for (int j=2;j*j<=A;j++)
		{
			if (A%j) continue;
			tmp.push_back(j);
			while (A%j==0) A/=j;
		}
		if (A!=1) tmp.push_back(A);
		int MAX=0;
		for (int j=0;j<tmp.size();j++) MAX=max(MAX,F[tmp[j]]);
		for (int j=0;j<tmp.size();j++) F[tmp[j]]=max(F[tmp[j]],MAX+1);
		Ans=max(Ans,MAX+1);
	}
	printf("%d\n",Ans);
}