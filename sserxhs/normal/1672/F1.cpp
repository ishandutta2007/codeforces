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
		cin>>n;
		vector<int> a(n),r(n),cnt(n+1),pt(n+1);
		for (int &x:a) cin>>x,++cnt[x];
		vector<vector<int>> s(*max_element(all(cnt)));
		for (i=0;i<n;i++) s[pt[a[i]]++].push_back(i);
		for (auto &v:s) if (v.size()>1)
		{
			sort(all(v),[&](const int &x,const int &y){return a[x]<a[y];});
			m=v.size();
			for (i=0;i+1<m;i++) r[v[i+1]]=a[v[i]];
			r[v[0]]=a[v[m-1]];
		} else if (v.size()) r[v[0]]=a[v[0]];
		for (i=0;i<n;i++) cout<<r[i]<<" \n"[i+1==n];
	}
}