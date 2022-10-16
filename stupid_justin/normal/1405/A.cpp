#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define R register
#define I inline
using namespace std;

const int M=1e7+5;
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

int cnt_prim;
int prim[M];
bool vis[M];
I void init()
{
	for (R int i=2;i<=M;i++)
	{
		if (vis[i]==0) prim[++cnt_prim]=i;
		for (R int j=1;j<=cnt_prim;j++)
		{
			if (prim[j]*i>M) break;
			vis[i*prim[j]]=1;
			if (i%prim[j]==0) break;
		}
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
		for (int i=n;i>=1;i--) cout<<a[i]<<" ";
		cout<<endl; 
	}
}