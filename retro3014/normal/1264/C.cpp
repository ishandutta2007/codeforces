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
#define test 0
#define TEST if(test)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ll MOD = 998244353;
const int INF = 2e9;
const ll INFLL = 1e18;
const int MAX_N = 200000;

ll multi(ll x, ll y){
	if(y==1)	return x%MOD;
	if(y==0)	return 1;
	ll m = multi(x, y/2);
	if(y%2){
		return (((m*m)%MOD)*x)%MOD;
	}
	return (m*m)%MOD;
}

ll inv10=0;

ll inv(ll x){
	if(x==10){
		if(inv10==0){
			inv10 = multi(10, MOD-2);
		}
		return inv10;
	}
	return multi(x, MOD-2);
}

int N, Q;
ll p[MAX_N+1];
bool chk[MAX_N+1];
ll ans;
set<int> st;

ll D1[MAX_N+1], D2[MAX_N+1], D3[MAX_N+1];
ll SD1[MAX_N+1], SD2[MAX_N+1], SD3[MAX_N+1];

ll calc(int s, int e){
	ll ret = 0;
	TEST cout<<s<<" "<<e<<endl;
	ret = (SD3[e] - SD3[s-1] + MOD) % MOD;
	ret = (ret + (((MOD - (ll)s + 1) % MOD) * ((SD2[e]-SD2[s-1]+MOD)%MOD)) % MOD) % MOD;
	ret = (ret + (D1[e]*(ll)(e-s+1) % MOD)) % MOD;
	ret = (ret * inv(D1[e])) % MOD;
	return ret;
}

int main(){
	scanf("%d%d", &N, &Q);
	ll m = 1;
	for(int i=1; i<=N; i++){
		scanf("%lld", &p[i]);
		D1[i] = ((m * p[i] % MOD) * inv(100)) % MOD;
		D2[i] = ((m * (100LL-p[i]) % MOD) * inv(100)) % MOD;
		D3[i] = (((m * (100LL-p[i]) % MOD) * inv(100) % MOD) * (ll)i) % MOD;
		TEST{
			cout<<D1[i]<<" "<<D2[i]<<" "<<D3[i]<<endl;
		}
		SD1[i] = (SD1[i-1] + D1[i]) % MOD; SD2[i] = (SD2[i-1] + D2[i]) % MOD; SD3[i] = (SD3[i-1] + D3[i]) % MOD;
		m = ((m * p[i] % MOD) * inv(100)) % MOD;
	}
	chk[1] = true;
	st.insert(1); st.insert(N+1);
	ans = calc(1, N);
	for(int i=1; i<=Q; i++){
		int x; scanf("%d", &x);
		if(chk[x]){
			st.erase(x); 
			int l, r; 
			set<int>::iterator it = st.lower_bound(x);
			r = (*it); it--; l = (*it);
			ans = (ans - calc(l, x-1) + MOD) % MOD;
			ans = (ans - calc(x, r-1) + MOD) % MOD;
			ans = (ans + calc(l, r-1)) %  MOD;
		}else{
			int l, r;
			set<int>::iterator it = st.lower_bound(x);
			r = (*it); it--; l = (*it);
			ans = (ans - calc(l, r-1) + MOD) % MOD;
			TEST cout<<calc(l, x-1)<<" "<<calc(x, r-1)<<endl;
			ans = (ans + calc(l, x-1) + calc(x, r-1)) % MOD;
			st.insert(x);
		}
		chk[x] = 1 - chk[x];
		printf("%lld\n", ans);
	}
	return 0;
}