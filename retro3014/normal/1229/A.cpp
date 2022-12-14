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
const int MAX_N = 7000;

int N;


vector<pll> v;
map<ll, int> cnt;
bool vst[MAX_N+1];


ll ans = 0;
ll k = 0;


int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		ll x, y;
		scanf("%lld", &x);
		v.pb({x, 0});
		cnt[x]++;
	}
	for(int i=0; i<N; i++){
		ll y;
		scanf("%lld", &y);
		v[i].second = y;
	}
	for(int i=0; i<N; i++){
		if(vst[i])	continue;
		if(cnt[v[i].first]>1){
			for(int j=0; j<N; j++){
				if(!vst[j] && (v[i].first & v[j].first) == v[j].first){
					vst[j] = true;
					ans += v[j].second;
				}
			}
		}
	}
	cout<<ans;

	return 0;
}