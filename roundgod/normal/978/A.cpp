#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
set<int> s;
vector<int> ans;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=n-1;i>=0;i--)
	{
		if(s.count(a[i])==0) ans.push_back(a[i]);
		s.insert(a[i]);
	}
	printf("%d\n",ans.size());
	for(int i=ans.size()-1;i>=0;i--)
		printf("%d ",ans[i]);
	return 0;
}