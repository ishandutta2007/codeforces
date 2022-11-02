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

		ll cnt[1010]={0,};
		while(n--){
			cin>>m;
			cnt[m]++;
		}
		ll cnt0=-1,cnt1=-1;
		for(i=0;i<=100;i++){
			if(cnt[i]<2&&cnt1==-1){
				cnt1=i;
			}
			if(cnt[i]<1&&cnt0==-1){
				cnt0=i;
			}
		}
		cout<<cnt1+cnt0<<'\n';
	}

}