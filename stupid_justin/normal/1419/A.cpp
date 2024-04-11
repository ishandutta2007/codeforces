#include<bits/stdc++.h>
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
		int n;
		int a[2][2];
		memset(a,0,sizeof(a));
		string str;
		cin>>n>>str;
		for (int i=0;i<n;i++) a[(i+1)%2][int(str[i]-'0')%2]++;
		if (n%2==1) 
		{
			if (a[1][1]) cout<<1<<endl;else cout<<2<<endl;
		}
		if (n%2==0)
		{
			if (a[0][0]) cout<<2<<endl;else cout<<1<<endl;
		}
		//if (n%2==1) 
	}
}