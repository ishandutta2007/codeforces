#include <bits/stdc++.h>
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
int cnt[26];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T;cin>>T;
	while (T--)
	{
		memset(cnt,0,sizeof cnt);
		int n,m,i,j;
		string s;cin>>s;n=s.size();
		for (auto c:s) ++cnt[c-'a'];
		for (i=0;i<n;i++) if (!--cnt[s[i]-'a']) break;
		cout<<s.substr(i)<<'\n';
	}
}