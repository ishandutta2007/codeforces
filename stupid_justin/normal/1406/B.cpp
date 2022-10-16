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
const int mod=1e9+7;
const int mod2=998244353;

I int ksm(int x,int y,int z){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}}

int n,m,k,ans,cnt,res;
int z,f,l;
int a[N];
int Z[N];
int F[N];
int num[N];
string str;
map<int,int> Map;
vector<int> vec[N];

void add(int u,int v){vec[u].push_back(v);vec[v].push_back(u);}




signed main()
{
	int T;
	cin>>T;
	while (T--)
	{
		cin>>n;
		z=f=l=0;
		for (int i=1;i<=n;i++) cin>>a[i];
		for (int i=1;i<=n;i++)
		{
			if (a[i]>0) Z[++z]=a[i];
			if (a[i]<0) F[++f]=a[i];
			if (a[i]==0) l++;
		}
		sort(Z+1,Z+z+1);
		sort(F+1,F+f+1);
		ans=-inf;
		if (z>=1 && f>=4) ans=max(Z[z]*F[3]*F[4]*F[1]*F[2],ans);
		if (z>=3 && f>=2) ans=max(Z[z]*Z[z-1]*Z[z-2]*F[1]*F[2],ans);
		if (z>=5 && f>=0) ans=max(Z[z]*Z[z-1]*Z[z-2]*Z[z-3]*Z[z-4],ans);
		if (l>0) ans=max(0ll,ans);
		//z=0 f=X z=2 f=3  z=4 f=2
		if (z==0) ans=max(F[f]*F[f-1]*F[f-2]*F[f-3]*F[f-4],ans);
		ans=max(ans,a[1]*a[2]*a[3]*a[4]*a[5]); 
		cout<<ans<<endl;
	}
}