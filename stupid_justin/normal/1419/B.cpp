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
int a[N];
int b[N];
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
		int x;
		cin>>x;
		int tmp1,tmp2,ans;
		tmp1=2,tmp2=0,ans=0;
		while (tmp2<=x)
		{
			tmp2+=(tmp1-1)*tmp1/2;
			tmp1<<=1;
			ans++;
		}
		cout<<ans-1<<endl;
	}
}