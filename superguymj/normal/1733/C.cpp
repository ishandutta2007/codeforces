#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
typedef long long LL;
const int N=100005;
int n,a[N];
vector <pair<int,int>> ans;

void solve()
{
	ans.clear();
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",&a[i]);
	int x=1;
	rep(i,1,n) if((a[i]&1)==(a[1]&1)) x=i;
	rep(i,1,x-1) if((a[i]&1)==(a[1]&1))
		ans.push_back(make_pair(i,x));
	rep(i,1,n) if((a[i]&1)!=(a[1]&1))
		ans.push_back(make_pair(1,i));
	printf("%d\n",ans.size());
	for(auto p:ans)
		printf("%d %d\n",p.first,p.second);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--) solve();
	return 0;
}