
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n;
vector<int> vec;
int sum,ans;
map<int,int> Map;
signed main()
{
	cin>>n;
	Map[0]=1;
	for (int i=1;i<=n;i++)
	{
		int a;
		scanf("%lld",&a);
		sum+=a;
		if (Map.find(sum)!=Map.end())
		{
			ans++;
			sum=a;
			Map.clear();
			Map[0]=1;
		}
		Map[sum]=a;
	}
	cout<<ans<<endl;

}