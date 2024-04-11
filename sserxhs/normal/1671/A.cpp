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
	int T;cin>>T;
	while (T--)
	{
		int n,m,i,j;
		string s,t="ba";
		cin>>s;
		s=t[s[0]-'a']+s+t[s.back()-'a'];
		n=s.size();
		for (i=1;i+1<n;i++) if (s[i]!=s[i-1]&&s[i]!=s[i+1]) break;
		if (i+1<n) cout<<"NO\n"; else cout<<"YES\n";
	}
}