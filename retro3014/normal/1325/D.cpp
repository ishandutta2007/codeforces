#include <bits/stdc++.h>

#define all(v) (v).begin(), (v).end()
#define sortv(v) sort(all(v))
#define uniqv(v) (v).erase(unique(all(v)), (v).end())
#define pb push_back
#define FI first
#define SE second
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define test 1
#define TEST if(test)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int MOD = 1000000007; // 998244353
const int INF = 2e9;
const ll INFLL = 1e18;
const int MAX_N = 300;

ll U, V;
ll ans[MAX_N+1];
int cnt[MAX_N+1];

vector<ll> v;

int main(){
	scanf("%lld%lld", &U, &V);
	ll S = V;
	V-=U;
	if(V<0){
		printf("-1");
		return 0;
	}
	for(ll i=60; i>=0; i--){
		int t = 0;
		if((U & (1LL<<i))!=0){
			t++;
		}
		while(V>=(1LL<<(i+1LL))){
			t+=2;
			V-=(1LL<<(i+1LL));
		}
		//cout<<i<<" "<<t<<endl;
		for(int j=0; j<t; j++)	ans[j]+=(1LL<<i);
	}
	for(int i=0; i<MAX_N; i++){
		S-=ans[i];
		if(ans[i]!=0LL){
			//cout<<ans[i]<<endl;
			v.pb(ans[i]);
		}
	}
	if(S!=0){
		printf("-1");
	}else{
		printf("%d\n", (int)v.size());
		for(ll i : v){
			printf("%lld ", i);
		}
	}
	return 0;
}