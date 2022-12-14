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

int T;
ll X, Y;

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%lld%lld", &X, &Y);
		ll s = 1, e = Y, m;
		ll ans = 0LL;
		while(s<e){
			m = (s+e)/2+1;
			if(m-1<=X/(m+1)){
				s = m;
			}else{
				e = m-1;
			}
		}
		ans = ans + s * (s-1) / 2LL;
		//cout<<"*"<<s<<endl;
		s++;
		while(s<=Y && s<X){
			//cout<<s<<" "<<X<<endl;
			ll d = X / (s+1);
			e = min(X / d - 1, Y);
			ans += d * (e-s+1LL);
			//cout<<d<<" "<<s<<" "<<e<<" "<<X<<" "<<Y<<endl;
			s = e+1LL;
		}
		printf("%lld\n", ans);
	}
	return 0;
}