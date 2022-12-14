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
 
const int MOD = 998244353;
const int INF = 2e9;
const ll INFLL = 1e18;
const int MAX_N = 100000;

int T, N;
vector<int> v;
ll sum[MAX_N+1];
ll cnt[MAX_N+1];
ll nsum[MAX_N+1];
ll ncnt[MAX_N+1];
vector<int> vt;
vector<int> nvt;
bool chk[MAX_N+1];

ll ans;
void add(ll x){
	x = x % MOD;
	ans = (ans + x) % MOD;
}

int main(){
	scanf("%d", &T);
	while(T--){
		ans = 0;
		scanf("%d", &N);
		v.clear();
		for(int i=0; i<N; i++){
			int x; scanf("%d", &x);
			v.pb(x);
		}
		vt.clear(); nvt.clear();
		vt.pb(MAX_N);
		sum[MAX_N] = 0;
		cnt[MAX_N] = 0;
		while(!v.empty()){
			int now = (int)v.back(); v.pop_back();
			TEST cout<<now<<endl;
			for(int j=0; j<vt.size(); j++){
				int mx = vt[j];
				ll cs = sum[mx], num = cnt[mx];
				int l = (now + mx - 1) / mx;
				ll ad = (cs + (num * (ll)(l-1) % MOD)) % MOD;
				add(ad);
				int nmx = now / l;
				TEST cout<<mx<<" "<<l<<" "<<nmx<<" "<<ad<<endl;
				if(!chk[nmx]){
					chk[nmx] = true;
					nvt.pb(nmx);
				}
				nsum[nmx] = (nsum[nmx] + cs) % MOD;
				nsum[nmx] = (nsum[nmx] + (num * (ll)(l-1) % MOD)) % MOD;
				ncnt[nmx] = (ncnt[nmx] + num) % MOD;
			}
			if(!chk[now]){
				chk[now] = true;
				nvt.pb(now);
			}
			nsum[now]+=0LL;
			ncnt[now]+=1LL;
			while(!vt.empty()){
				sum[vt.back()] = 0LL; cnt[vt.back()] = 0LL;
				vt.pop_back();
			}
			while(!nvt.empty()){
				chk[nvt.back()] = false;
				sum[nvt.back()] = nsum[nvt.back()];
				cnt[nvt.back()] = ncnt[nvt.back()];
				nsum[nvt.back()] = 0LL;
				ncnt[nvt.back()] = 0LL;
				vt.pb(nvt.back());
				nvt.pop_back();
			}
		}
		while(!vt.empty()){
			sum[vt.back()] = 0LL;
			cnt[vt.back()] = 0LL;
			vt.pop_back();
		}
		printf("%lld\n", ans);
	}
	return 0;
}