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
string st="theseus";
string s[100];
int cnt[26];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int n,i,j,k,m=st.size();
	cin>>n;
	for (i=0;i<n;i++) cin>>s[i];
	for (i=0;i+m<=n;i++) for (j=0;j+m<=n;j++)
	{
		string t;
		for (k=0;k<m;k++) t+=s[i+k][j+k];
		if (t==st) return cout<<"YES\n",0;
	}
	cout<<"NO\n";
}