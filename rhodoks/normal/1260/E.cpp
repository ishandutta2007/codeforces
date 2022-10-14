#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 510000
#define MAXM 410000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int n;
int a[MAXN];
int k;
LL ans;
priority_queue<int,vector<int>,greater<int> > q;

int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if (a[i]==-1)
			k=i;
	}
	int res=n-k;
	int t=n;
	while (res>0)
	{
		q.push(a[t]);
		ans+=q.top();
		//WRT(ans);
		q.pop();
		t>>=1;
		res-=t;
		for (int i=2*t-1;i>t;i--)
			q.push(a[i]);
	}
	cout<<ans;
	return ~~(0^_^0);
}