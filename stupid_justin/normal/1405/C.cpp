#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define R register
#define I inline
#define endit {flag=1;break;}
#define outno {cout<<"NO"<<endl;continue;}
using namespace std;

const int N=3e5+5;
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
int pre[N];
int ppp[N];
int should[N];
char STR[N];
char ch[N];
map<int,int> Map;
map<int,bool> Vis;

signed main()
{
	int T;
	cin>>T;
	while (T--)
	{
		cin>>n>>k;
		for (int i=0;i<=n;i++) should[i]=-1;
		string str;
		cin>>str;
		//str[x]str[x+k]
		bool flag=0;
		for (int i=0;i<n;i++)
		{
			if (flag) break;
			if (str[i]!='?')
			for (int j=i+k;j<n;j+=k)
			{
				if (str[j]!='?' && str[j]!=str[i]) endit
				if (should[j]!=-1 && should[j]!=str[i]-'0') endit
				if (should[j]!=-1) break;
				should[j]=str[i]-'0';
			}
		}
		if (flag) outno
		for (int i=0;i<n;i++) 
		{
			if (str[i]!='?') STR[i]=str[i];else
			if (should[i]!=-1) STR[i]=should[i]+'0';
			else STR[i]='?';
		}
		int num1=0,num0=0,numw=0;
		for (int i=0;i<k;i++)
		{
			if (STR[i]=='1') num1++;
			if (STR[i]=='0') num0++;
			if (STR[i]=='?') numw++;
		}
		if (num1>k/2 || num0>k/2) outno
		for (int i=k;i<n;i++)
		{
			if (STR[i]=='1') num1++;
			if (STR[i]=='0') num0++;
			if (STR[i]=='?') numw++;
			if (STR[i-k]=='1') num1--;
			if (STR[i-k]=='0') num0--;
			if (STR[i-k]=='?') numw--;
			if (num1>k/2 || num0>k/2) endit
		}
		if (flag) outno
		cout<<"YES"<<endl;
	}
}