#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define R register
#define I inline
using namespace std;

const int N=1e5+5;
const int inf=0x3f3f3f3f3f3f3f3f;
const int mod1=1e9+7;
const int mod2=998244353;

I int ksm(int x,int y,int z)
{
	int ret=1;
	while (y)
	{
		if (y&1) ret=(ret*x)%z;
		x=(x*x)%z;
		y>>=1;
	}
}

vector<int> vec[N];

void add(int u,int v)
{
	vec[u].push_back(v);
	vec[v].push_back(u);
}


int n,m,k,ans,cnt,res;

int a[N];

map<int,int> Map;


signed main()
{
	int T;
	cin>>T;
	while (T--)
	{
		cin>>n;
		for (int i=1;i<=n;i++) cin>>a[i];
		int sum=0;
		ans=0;
		for (int i=1;i<=n;i++) 
		{
			sum+=a[i];
			ans=min(ans,sum);
		}
		cout<<-ans<<endl;
	}
}