#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll,ll> pii;
#define ff first
#define ss second 
#define pb push_back

ll vis[1010101];
ll dep[1010101];
ll ans[1010101];

vector<pii> v[1010101];
vector<pii> v2[1010101];
vector<pii> v3[1010101];

ll cnt[1091010];

ll dp[1010101];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll t;
	cin>>t;
	while(t--){
		ll i,j,k,l,m,n;
		cin>>n;

		ll cnt[101010]={0,};
		vector<ll> pl;
		vector<ll> mi;
		pl.clear();
		mi.clear();
		for(i=1;i<=n;i++){
			cin>>cnt[i];
		}
		sort(cnt+1,cnt+1+n);
		cout<<max({cnt[n-4]*cnt[n-3]*cnt[n]*cnt[n-1]*cnt[n-2],cnt[1]*cnt[2]*cnt[n]*cnt[n-1]*cnt[n-2],cnt[1]*cnt[2]*cnt[n]*cnt[4]*cnt[3]})<<'\n';


	}

}