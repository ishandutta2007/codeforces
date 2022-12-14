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

const int MOD = 1000000007; // 998244353
const int INF = 2e9;
const ll INFLL = 1e18;
const int MAX_N = 1000000;

int N;
ll arr[MAX_N+1];
ll a[MAX_N+1];
ll sum = 0;
vector<ll> v;
vector<pll> vt;
ll S, answer = INFLL, ans;

void calc(){
	ll ret = INFLL;
	ll s = 0, add = 0, p;
	p = vt[0].first;
	for(pll i : vt){
		s += (i.first - p) * i.second;
		add -= i.second;
	}
	ret = min(ret, s);
	for(pll i : vt){
		TEST cout<<s<<" "<<i.first<<" "<<i.second<<endl;
		add += (ll)2 * i.second;
		s += add;
		ret = min(ret, s);
	}
	ans+=ret;
	TEST cout<<ret<<endl;
	while(!vt.empty()){
		vt.pop_back();
	}
	return;
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%lld", &arr[i]);
		sum += arr[i];
	}
	if(sum<=1){
		printf("-1");
		return 0;
	}
	for(ll i=2; i*i<=sum; i++){
		if(sum%i==0){
			v.pb(i);
			while(sum%i==0){
				sum/=i;
			}
		}
	}
	if(sum!=1)	v.pb(sum);
	for(ll n : v){
		TEST cout<<n<<endl;
		ans = 0;
		for(int i=0; i<N; i++){
			a[i] = arr[i];
		}
		for(int i=0; i<N; i++){
			if(S+a[i]>=n){
				a[i] -= (n-S);
				vt.pb({i, n-S});
				calc();
				S = 0;
			}
			a[i] = a[i] % n;
			vt.pb({i, a[i]});
			S += a[i];
		}
		answer = min(answer, ans);
		TEST cout<<ans<<endl;
		while(!vt.empty())	vt.pop_back();
	}
	cout<<answer;
	return 0;
}