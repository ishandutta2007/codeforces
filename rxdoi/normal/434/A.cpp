#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long LL;
const int Maxn=1e5+19;
const LL oo=1LL<<60;
int n,m;
LL sco,Ans=oo,pre;
int A[Maxn];
vector<int> near[Maxn];

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++) 
	{
		scanf("%d",&A[i]);
		if (i&&A[i]==A[i-1]) i--,m--;
			else 
				if (i) 
				{
					near[A[i]].push_back(A[i-1]);
					near[A[i-1]].push_back(A[i]);
				}
	}
	if (m==1) {printf("0\n");return 0;}
	for (int i=1;i<m;i++) pre+=abs(A[i]-A[i-1]);
	for (int i=1;i<=n;i++)
		{
			sco=0;
			if (near[i].empty()) continue;
			vector<int> tmp=near[i];
			sort(tmp.begin(),tmp.end());
			int _new=tmp[tmp.size()/2];
			sco=pre;
			for (int j=0;j<tmp.size();j++) 
				sco=sco+abs(tmp[j]-_new)-abs(tmp[j]-i);
			Ans=min(Ans,sco);
		}
	printf("%I64d\n",Ans);
}