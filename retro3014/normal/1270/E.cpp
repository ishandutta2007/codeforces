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
const int MAX_N = 1000;

int N;
vector<pll> vt;

struct S{
	ll dist, x, y;
	bool operator <(const S &a)const{
		return dist<a.dist;
	}
};
vector<S> v;
vector<int> ans;

int main(){
	scanf("%d", &N);
	for (int i = 0; i < N; ++i){
		ll a, b; scanf("%lld%lld", &a, &b);
		vt.pb({a, b});
	}
	for(int i=0; i<N; i++){
		vt[i].first-=vt[N-1].first;
		vt[i].second-=vt[N-1].second;
	}
	while(ans.empty()){
		for(int i=0; i<N; i++){
			if((vt[i].first+vt[i].second)%2!=0){
				ans.pb(i+1);
			}
		}
		if(!ans.empty())	break;
		for(int i=0; i<N; i++){
			if(vt[i].first%2!=0){
				ans.pb(i+1);
			}
			vt[i].first/=2;
			vt[i].second/=2;
		}
	}
	printf("%d\n", (int)ans.size());
	for(int i=0; i<ans.size(); i++){
		printf("%d ", ans[i]);
	}
	return 0;
}