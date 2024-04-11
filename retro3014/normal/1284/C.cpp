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
const int MAX_N = 250000;

ll N, M;
ll ans = 0;
ll per[MAX_N+1];

int main(){
	cin>>N>>M;	
	per[0] = per[1] = 1;
	for(ll i=2; i<=N; i++){
		per[i] = (per[i-1] * i) % M;
	}
	for(ll k = 0; k<=N-1; k++){
		ll add = 0;
		add = per[k+1];
		add = (add * (N-k) % M) * (N-k) % M;
		add = (add * per[N-k-1]) % M;
		ans = (ans + add) % M;
	}
	cout<<ans;
	return 0;
}