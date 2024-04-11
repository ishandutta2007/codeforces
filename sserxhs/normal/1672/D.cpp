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
int lst[2][N];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T;cin>>T;
	while (T--)
	{
		int n,m,i,j;
		cin>>n;//,
		vector<int> a(n),b(n),cnt(n+1),del(n+1),lst(n+1);
		//for (i=0;i<=n;i++) lst[0][i]=lst[1][i]=-1;
		for (int &x:a) cin>>x;
		for (int &x:b) cin>>x;
		for (i=0;i<n;i++) lst[a[i]]=i;
		for (i=j=0;i<n&&j<n;j++)
		{
			if (a[i]==b[j])
			{
				if (del[a[i]]) --del[a[i]]; else ++i;
			}
			else if (lst[a[i]]>j)
			{
				++del[a[i]];
				--j;
				++i;
			} else break;
		}
		/*for (i=0;i<n;i++) lst[0][a[i]]=i,lst[1][b[i]]=i;
		vector<pair<int,int>> c,d;
		for (i=0;i<=n;i++) if (lst[0][i]!=-1) c.push_back({lst[0][i],i});
		for (i=0;i<=n;i++) if (lst[1][i]!=-1) d.push_back({lst[1][i],i});
		sort(all(c));sort(all(d));
		for (i=0;i<c.size();i++) if (c[i].second!=d[i].second) break;*/
		/*for (j=1;j<n;j++) if (b[j-1]==b[j])
		{
			++cnt[b[j]];
		}
		for (i=j=0;i<n;i++)
		{
			dbg(i,j);
			if (a[i]==b[j])
			{
				if (j<n&&b[j]==b[j+1]) --cnt[b[j]];
				++j;
				continue;
			}
			if (del[a[i]])
			{
				--del[a[i]];
				break;
			}
			if (!cnt[a[i]]) break;
			--cnt[a[i]];
		}*/
		if (j==n) cout<<"YES\n"; else cout<<"NO\n";
	}
}