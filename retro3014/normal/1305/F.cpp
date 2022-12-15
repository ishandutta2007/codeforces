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
const int MAX_N = 200000;
const ll MAX_K = 1e6;

vector<ll> prime;
double d = 6.0;
int cnt = 0;

void init_prime(){
	prime.pb(2LL);
	prime.pb(3LL);
	for(ll i=5; i<=MAX_K; i+=2LL){
		bool tf = true;
		for(ll j : prime){
			if(i%j==0){
				tf = false;
				break;
			}
			if(j*j>i)	break;
		}
		if(tf){
			prime.pb(i);
			// d *=(double)i;
			// while(d>1e12){
			// 	d=(double)i;
			// 	cnt++;
			// }
			//cout<<i<<endl;
		}//
	}
	//cout<<cnt<<endl;
	//cout<<prime.size();
}

int N;
vector<ll> v;
vector<ll> dv;

bool chk[MAX_N+1];
vector<int> lft;

int main(){
	srand(3014);
	init_prime();
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		ll x; scanf("%lld", &x); v.pb(x);
	}
	for(int i=0; i<N; i++){
		lft.pb(i);
	}
	ll ans = N, C = min(30, N);
	while(C--){
		if(lft.empty())	break;
		int n;
		n = (rand()*100+rand())%lft.size();
		int tmp = n; n = lft[n]; lft[tmp] = lft.back(); lft.pop_back();
		for(ll i=max(1LL, v[n]-1); i<=v[n]+1; i++){
			ll X = i;
			for(ll j : prime){
				if(X%j==0){
					dv.pb(j);
					while(X%j==0)	X/=j;
				}
				if(j*j>X)	break;
			}
			if(X!=1LL)	dv.pb(X);
			while(!dv.empty()){
				ll d = dv.back(); dv.pop_back();
				ll cnt = 0;
				for(ll Y : v){
					ll add = d-(Y%d);
					if(Y/d!=0)	add = min(add, d-add);
					cnt+=add;
					if(cnt>ans)	break;
				}
				ans = min(cnt, ans);
			}
		}
	}
	printf("%lld", ans);
	return 0;
}