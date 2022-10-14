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

#define MAXN 110000
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

vector<int> v[MAXN];
int mx[MAXN];
int mi[MAXN];
int flag[MAXN];
int n;
int tmp[MAXN];
int buc[1100000];
int main()
{
	cin>>n;
	int x;
	int y;
	for (int i=0;i<n;i++)
	{
		scanf("%d",&x);
		mx[i]=0;
		mi[i]=INF;
		while (x--)
		{
			scanf("%d",&y);
			v[i].push_back(y);
			mx[i]=max(mx[i],y);
			mi[i]=min(mi[i],y);
			if (y>mi[i])
				flag[i]=1;
		}
	}
	int cnt=0;
	for (int i=0;i<n;i++)
		if (!flag[i])
		{
			buc[mi[i]+1]++;
			cnt++;
		}
	cnt=n-cnt;
	//WRT(cnt);
	for (int i=1;i<=1010000;i++)
		buc[i]=buc[i-1]+buc[i];
	LL ans=0;
	for (int i=0;i<n;i++)
		if (!flag[i])
		{
			ans+=buc[mx[i]];
			//WRT(buc[mx[i]]);
		}
	//WRT(ans);
	ans+=(LL)2*cnt*n-(LL)cnt*cnt;
	cout<<ans;
	return ~~(0^_^0);
}