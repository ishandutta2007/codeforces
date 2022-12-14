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

int T;
ll N;

vector<pii> vt;
int type;
pii p[4][4];
pii p2[4];

int main(){
	p[1][0] = {0, 0}; p[2][0] = {0, 0}; p[3][0] = {0, 0};
	p[1][1] = {0, 1}; p[2][1] = {1, 0}; p[3][1] = {1, 1};
	p[1][2] = {1, 0}; p[2][2] = {1, 1}; p[3][2] = {0, 1};
	p[1][3] = {1, 1}; p[2][3] = {0, 1}; p[3][3] = {1, 0};
	p2[1] = {0, 1}; p2[2] = {1, 0}; p2[3] = {1, 1};
	scanf("%d", &T);
	for(int i=1; i<=T; i++){
		scanf("%lld", &N);
		ll G = (N+2)/3-1LL;
		type = (N-1)%3+1;
		int len = 1;
		while(!vt.empty())	vt.pop_back();
		ll now = 1LL;
		while(1){
			if(G<now){
				for(int i=1; i<len; i++){
					vt.pb(p[type][G%4]);
					G/=4;
				}
				vt.pb(p2[type]);
				break;
			}else{
				G-=now;
				now*=4LL;
				len++;
			}
		}
		ll ans = 0LL;
		while(!vt.empty()){
			ans*=4LL;
			ans+=(ll)vt.back().first*2LL+(ll)vt.back().second;
			vt.pop_back();
		}
		printf("%lld\n", ans);
	}
	return 0;
}