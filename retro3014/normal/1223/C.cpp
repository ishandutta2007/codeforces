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

int Q;
int N;
vector<ll> P;
ll x, y, a, b;
ll k;

vector<ll> v;

ll calc(int z){
	while(!v.empty())	v.pop_back();
	for(int i=1; i<=z; i++){
		ll t = 0;
		if(i%a==0){
			t+=x;
		}if(i%b==0){
			t+=y;
		}
		if(t!=0){
			v.pb(t);
		}
	}
	sort(v.begin(), v.end());
	int idx = P.size()-1;
	ll ret = 0;
	while(!v.empty()){
		ret += (P[idx] / (ll)100 * v.back());
		v.pop_back();
		idx--;
	}
	return ret;
}

int main(){
	cin>>Q;
	while(Q--){
		scanf("%d", &N);
		while(!P.empty())	P.pop_back();
		for(int i=0; i<N; i++){
			ll t; scanf("%lld", &t);
			P.pb(t);
		}
		sort(P.begin(), P.end());
		scanf("%lld%lld%lld%lld%lld", &x, &a, &y, &b, &k);
		int s = 1, e = N, m;
		while(s<e){
			m = (s+e)/2;
			if(calc(m)>=k){
				e = m;
			}else{
				s = m+1;
			}
		}
		if(calc(s)>=k){
			printf("%d\n", s);
		}else{
			printf("-1\n");
		}
	}
	return 0;
}