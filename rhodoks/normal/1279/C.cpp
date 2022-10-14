#include <bits/stdc++.h>
#define INL inline
#define REG register
#define DB double
#define LDB long double
#define ULL unsigned long long
#define LL long long

#define RPT(i,x,y) for (REG int i=(x);i<(y);i++)
#define DRPT(i,x,y) for (REG int i=(x);i>(y);i--)
#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 210000
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int n,m;
int a[MAXN],b[MAXN];
bool visit[MAXN];
int pos[MAXN];

int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		cin>>n>>m;
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]); 
			pos[a[i]]=i;
		}
		for (int i=1;i<=m;i++)
		{
			scanf("%d",&b[i]); 
			visit[b[i]]=1;
		}
		int ptr=1;
		LL ans=0;
		int len=0;
		for (int i=1;i<=m;i++)
		{
			if (!visit[b[i]])
				continue;
			ans+=2*(pos[b[i]]-i+1)-1;
			visit[b[i]]=0;
			//WRT(ans);
			for (int j=ptr;j<pos[b[i]];j++)
				if (visit[a[j]])
				{
					visit[a[j]]=0;
					ans++;
				}
			ptr=pos[b[i]]+1;
		}
		cout<<ans<<endl;
	}
	return ~~(0^_^0);
}