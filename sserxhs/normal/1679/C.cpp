//114514min
#include "bits/stdc++.h"
using namespace std;
#if !defined(ONLINE_JUDGE)&&defined(LOCAL)
#include "my_header\debug.h"
#else
#define dbg(...) ;
#define dbgn(...) ;
#endif
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int N=1e6+5;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int n,m,i;
	cin>>n>>m;
	set<int> s[2];
	vector<vector<int>> cnt(2,vector<int>(n+1));
	for (auto &v:s) for (i=1;i<=n;i++) v.insert(i);
	while (m--)
	{
		int op,a[2];
		cin>>op>>a[0]>>a[1];
		if (op==3)
		{
			int b[2];
			cin>>b[0]>>b[1];
			bool flg=0;
			for (i=0;i<2;i++) flg|=s[i].lower_bound(a[i])==s[i].upper_bound(b[i]);
			cout<<(flg?"Yes\n":"No\n");
		}
		else if (op==2)
		{
			for (i=0;i<2;i++) if (!--cnt[i][a[i]]) s[i].insert(a[i]);
		}
		else
		{
			for (i=0;i<2;i++) if (!cnt[i][a[i]]++) s[i].erase(a[i]);
		}
	}
}