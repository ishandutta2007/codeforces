#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<n;++i)
#define repn(i,n) for(int i=1;i<=n;++i)
#define LL long long
#define pii pair <int,int>
#define fi first
#define se second
#define mpr make_pair
#define pb push_back

using namespace std;

int t,n,k,cnt[30];
string s,ans;

int main()
{
	ios::sync_with_stdio(false);
	cin>>t;
	rep(tn,t)
	{
		cin>>n>>k>>s;
		rep(i,29) cnt[i]=0;
		rep(i,s.size()) ++cnt[s[i]-'a'];
		ans="";
		rep(i,k)
		{
			int rec=0;
			rep(j,min(25,n/k))
			{
				if(cnt[j]==0) break;
				--cnt[j];++rec;
			}
			ans.pb(rec+'a');
		}
		cout<<ans<<endl;
	}
	return 0;
}