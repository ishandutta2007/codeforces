#include <bits/stdc++.h>
#define DB double
#define LL long long
 
#define MST(a,b) memset((a),(b),sizeof(a))
 
#ifdef _DEBUG_
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;
#else
#define MRK() ;
#define WRT(x) ;
#endif
 
#define MAXN 1010000
#define MAXM 2010000
#define MOD 998244353  //1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5
 
#define _ 0
using namespace std;
 
int n;
int a[MAXN];
int buc[MAXN];
int cnt[MAXN][2];
bool flag[MAXN];
typedef pair<int,int> pii;
void work()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		buc[i]=cnt[i][0]=cnt[i][1]=0;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		buc[a[i]]++;
	}
	if (n==1)
	{
		cout<<0<<endl;
		return;
	}
	for (int i=1;i<=n;i++)
	{
		if (buc[i]>(n+1)/2)
		{
			cout<<-1<<endl;
			return;
		}
	}
	int lst=1;
	vector<pii> v;
	for (int i=1;i<=n-1;i++)
	{
		if (a[i]==a[i+1])
		{
			v.push_back({a[lst],a[i]});
			//cout<<a[lst]<<" ! "<<a[i]<<endl;
			lst=i+1;
		}
			
	}
	v.push_back({a[lst],a[n]});
	if (v.size()==1)
	{
		cout<<0<<endl;
		return ;
	}
	//cout<<v.size()<<endl;
	//for (auto p:v)
	//	cout<<p.first<<' '<<p.second<<endl;
	for (int i=0;i<v.size();i++)
		cnt[v[i].first][0]++;
	for (int i=0;i<v.size();i++)
	{
		cnt[v[i].second][1]++;
	}
	for (int i=1;i<=n;i++)	
	{
		//cout<<cnt[i][0]<<' '<<cnt[i][1]<<endl;
		//WRT(v.size())
		//	WRT(cnt[i][0]+cnt[i][1])
		if (cnt[i][0]+cnt[i][1]>v.size()+1)
		{
			printf("%d\n",v.size()-1+cnt[i][0]+cnt[i][1]-v.size()-1);
			//cout<<v.size()+buc[i][0]+buc[i][1]-n<<endl;
			return ;
		}
	}
	printf("%d\n",v.size()-1);
}
 
int main()
{
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
	int t;
	cin>>t;
	while (t--)
		work();
	return ~~(0^_^0);
}