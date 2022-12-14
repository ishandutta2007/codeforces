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

int N;
vector<pll> vt;

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		ll x; scanf("%lld", &x);
		if(vt.empty()){
			vt.pb({x, 1});
		}
		else{
			ll sum = x, cnt = 1LL;
			while(!vt.empty()){
				pll now = vt.back();
				if(now.first*cnt>=now.second*sum){
					vt.pop_back();
					sum+=now.first;
					cnt+=now.second;
				}else{
					break;
				}
			}
			vt.pb({sum, cnt});
		}
	}
	for(int i=0; i<vt.size(); i++){
		pll now = vt[i];
		for(int j=0; j<now.second; j++){
			printf("%.9lf\n", (double)now.first/(double)now.second);
		}
	}
	return 0;
}