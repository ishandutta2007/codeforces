#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 210000
#define MAXM 410000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

vector<int> v[2];
 
int main()
{
	int n,x;
	cin>>n;
	for (int i=0;i<n;i++)
	{
		scanf("%d",&x);
		v[x&1].push_back(x);
	}
	sort(v[0].begin(),v[0].end());
	sort(v[1].begin(),v[1].end());
	if (v[0].size()==v[1].size())
	{
		cout<<0;
		return 0;
	}
	if (v[0].size()>v[1].size())
		swap(v[0],v[1]);
	int ans=0;
	for (int i=0;i<v[1].size()-v[0].size()-1;i++)
		ans+=v[1][i];
	cout<<ans;
	return ~~(0^_^0);
}