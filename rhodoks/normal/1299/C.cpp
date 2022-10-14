#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 1010000
#define MAXM 410000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

typedef pair<int,DB> pid;
pid stk[MAXN];
int top=0; 
DB ans[MAXN];
int main()
{
	int n,x;
	DB sum=0;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		sum+=1000000-x;
		while (top>=1 && 
		(sum-stk[top].second)/(i-stk[top].first)
		> (stk[top-1].second-stk[top].second)/(stk[top-1].first-stk[top].first))
			top--;
		stk[++top]={i,sum};
	}
	//WRT(top);
	//for (int i=1;i<=n;i++)
	//	cout<<stk[i].first<<' '<<stk[i].second<<endl;
	for (int i=1;i<=top;i++)
		for (int j=stk[i-1].first+1;j<=stk[i].first;j++)
			ans[j]=(stk[i].second-stk[i-1].second)/(stk[i].first-stk[i-1].first);
	for (int i=1;i<=n;i++)
		printf("%.10lf\n",1000000-ans[i]);
	return ~~(0^_^0);
}