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
const int MAX_N = 100000;

ll N, arr[MAX_N+1];
int T, M;
vector<ll> vt;

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%lld%d", &N, &M);
		while(!vt.empty())	vt.pop_back();
		for(int i=1; i<=M; i++){
			ll x; scanf("%lld", &x);
			vt.pb(x);
		}
		sort(vt.begin(), vt.end());
		int idx = 0;
		int cnt = 0;
		int ans = 0;
		bool tf = true;
		for(ll t = 1; t<=N; t*=2LL){
			while(idx<vt.size() && vt[idx]==t){
				cnt++;
				idx++;
			}
			//cout<<t<<" "<<cnt<<endl;
			if((N&t)!=0){
				if(cnt==0){
					if(idx==vt.size()){
						tf = false;
						break;
					}else{
						ll n = vt[idx];
						idx++;
						//cout<<n<<endl;
						while(t*2LL<n){
							ans++;
							t*=2LL;
							//cout<<ans<<" "<<t<<endl;
						}
						ans++;
					}
				}else{
					cnt--;
				}
			}
			cnt/=2LL;
		}
		if(tf){
			printf("%d\n", ans);
		}else{
			printf("-1\n");
		}
	}
	return 0;
}