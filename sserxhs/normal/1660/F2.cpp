#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#if !defined(ONLINE_JUDGE)&&defined(LOCAL)
#include "my_header\debug.h"
#else
#define dbg(...) ;
#define dbgn(...) ;
#endif
typedef unsigned int ui;
typedef long long ll;
typedef pair<int,int> pa;
#define all(x) (x).begin(),(x).end()
const int N=1e6+5;
int a[N],b[N];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T;cin>>T;
	while (T--)
	{
		int n,m,i,j;
		tree<pa,null_type,less<pa>,rb_tree_tag,tree_order_statistics_node_update> cnt[3];
		string s;
		cin>>n>>s;
		for (i=1;i<=n;i++) a[i]=s[i-1]=='+'?2:1,b[i]=s[i-1]=='+'?-1:1;
		ll r=0;cnt[0].insert({0,0});
		for (i=1;i<=n;i++)
		{
			(a[i]+=a[i-1])%=3;
			b[i]+=b[i-1];
			r+=cnt[a[i]].order_of_key({b[i],n+1});
			//dbg(r,b[i]);
			cnt[a[i]].insert({b[i],i});
		}
		cout<<r<<'\n';
	}
}