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
		priority_queue<ll> p,q;
		ll tot=0;
		while (n--)
		{
			int x;cin>>x;
			q.push(x);tot+=x;
		}
		p.push(tot);
		while (q.size())
		{
			ll r=p.top();p.pop();
			if (r==q.top()) {q.pop();continue;}
			if (r<q.top()) break;
			p.push(r>>1);p.push(r-(r>>1));
		}
		if (!q.size()) cout<<"YES\n"; else cout<<"NO\n";
	}
}