#include <bits/stdc++.h>

#define all(v) (v).begin(), (v).end()
#define sortv(v) sort(all(v))
#define uniqv(v) (v).erase(unique(all(v)), (v).end())
#define pb push_back
#define FI first
#define SE second
#define lb lower_bound
#define ub upper_bound
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
const int MAX_A = 100001;

int N, K;
vector<int> v;
map<int, int> mp;
ll ans = 0;

int main(){
	scanf("%d%d", &N, &K);
	for(int i=0; i<N; i++){
		int x; scanf("%d", &x);
		int y=1, z=1;
		for(int j=2; j*j<=x; j++){
			if(x%j==0){
				int cnt = 0;
				while(x%j==0){
					x = x / j;
					cnt++;
				}
				cnt = cnt % K;
				for(int k=0; k<cnt; k++){
					y = y*j;
				}
				for(int k=0; k<(K-cnt)%K; k++){
					z = min(z*j, MAX_A);
				}
			}
		}
		if(x!=1){
			int cnt = 1;
			int j = x;
			cnt = cnt % K;
			for(int k=0; k<cnt; k++){
				y = y*j;
			}
			for(int k=0; k<K-cnt; k++){
				z = min(z*j, MAX_A);
			}
		}
		ans += (ll)mp[z];
		mp[y]++;
		//cout<<z<<" "<<y<<endl;
	}
	cout<<ans;
	return 0;
}