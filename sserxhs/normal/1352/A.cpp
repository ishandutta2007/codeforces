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
int mi[N];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T;cin>>T;
	mi[0]=1;
	for (int i=1;i<=8;i++) mi[i]=mi[i-1]*10;
	while (T--)
	{
		int n,m,i,j;
		string s;
		cin>>s;n=s.size();
		vector<int> a;
		for (i=0;i<n;i++) if (s[i]!='0') a.push_back((s[i]-'0')*mi[n-i-1]);
		cout<<a.size()<<'\n';
		for (i=0;i<a.size();i++) cout<<a[i]<<" \n"[i==a.size()-1];
	}
}