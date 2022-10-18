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
int a[2][N];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int n,m,i;
	string s;
	cin>>n>>m>>s;
	for (i=1;i<n;i++) if (s[i]==s[i-1]) a[s[i]-'0'][i+1]=1;
	for (i=1;i<=n;i++) a[0][i]+=a[0][i-1],a[1][i]+=a[1][i-1];
	while (m--)
	{
		int l,r;
		cin>>l>>r;
		cout<<max(a[0][r]-a[0][l],a[1][r]-a[1][l])+1<<'\n';
	}
}