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
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T;cin>>T;
	while (T--)
	{
		int n,m,i,j;
		string s;
		cin>>s;
		n=0;
		if (s.back()=='A')
		{
			cout<<"NO\n";
			goto no;
		}
		for (auto c:s) if (c=='A') ++n; else if (--n<0)
		{
			cout<<"NO\n";
			goto no;
		}	
		cout<<"YES\n";
		no:;
	}
}