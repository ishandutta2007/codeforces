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
const int N=2e5+5;
vector<int> e[N];
bool ed[N],ins[N],flg;
void dfs(int u)
{
	ins[u]=1;ed[u]=1;
	for (int v:e[u]) if (ed[v])
	{
		flg&=!ins[v];
	} else dfs(v);
	ins[u]=0;
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int T;cin>>T;
	while (T--)
	{
		int n,i,j;
		cin>>n;flg=1;
		for (i=1;i<=n;i++) e[i].clear();
		vector<int> a(n),b(n),cnt(n+1);
		for (int &x:a) cin>>x,++cnt[x];
		for (int &x:b) cin>>x;
		int mx=max_element(all(cnt))-cnt.begin();
		for (i=0;i<n;i++) if (a[i]!=mx&&b[i]!=mx) e[a[i]].push_back(b[i]);
		fill_n(ed+1,n,0);
		for (i=1;i<=n;i++) if (!ed[i]) dfs(i);
		if (flg) cout<<"AC\n"; else cout<<"WA\n";
	}
}