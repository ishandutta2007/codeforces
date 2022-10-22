#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	int n;
	scanf("%d",&n);
	vector<int> a(n);
	for(int &x: a) scanf("%d",&x);
	
	map<int,vector<int> > t;
	for(int i=0; i<n; ++i)
		t[a[i]].push_back(i);
	
	int ans = -1;
	for(auto &it: t)
	{
		auto &vec = it.second;
		for(int i=0; i+1<(int)vec.size(); ++i)
		{
			int x = vec[i], y = vec[i+1];
			ans = max(ans, x + (n-y));
		}
	}
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}