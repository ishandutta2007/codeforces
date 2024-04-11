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
const int MAX_N = 1;

ll A, B;
ll N, M;
ll ans;

int main(){
	cin>>N>>M;
	A = 1; B = 1;
	for(int i=1; i<min(N, M); i++){
		ll tmp = B;
		B = (A+B) % MOD;
		A = tmp;
	}
	ans = (B-1) * 2;
	for(int i=min(N, M); i<max(N, M); i++){
		ll tmp = B;
		B = (A+B) % MOD;
		A = tmp;
	}
	ans = (ans + (B-1)*2) % MOD;
	ans = (ans + 2) % MOD;
	cout<<ans;
	return 0;
}