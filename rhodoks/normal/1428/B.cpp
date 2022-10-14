#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 1010000
#define MAXM 2010000
#define MOD 998244353  //1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

void work()
{
	int n;
	string s;
	cin>>n>>s;
	int cnt[3]={0,0,0};
	for (int i=0;i<n;i++)
		if (s[i]=='>')
			cnt[0]++;
		else if (s[i]=='<') 
			cnt[1]++;
		else
			cnt[2]++;
	if (cnt[0]==0 || cnt[1]==0)
	{
		printf("%d\n",n);
		return;
	}
	vector<int> v;
	v.resize(n); 
	int ans=0;
	for (int i=0;i<n;i++)
	{
		if (s[i]=='-')
		{
			v[i]=1;
			v[(i+1)%n]=1;
		}
	}
	for (int i=0;i<n;i++)
		if (v[i])
			ans++;
	printf("%d\n",ans);
}

int main()
{
	int t;
	cin>>t;
	while (t--)
		work();
	return ~~(0^_^0);
}