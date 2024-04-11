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
vector<int> v;
vector<int> vt;

int main(){
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		int x;
		scanf("%d", &x);
		v.pb(x);
	}
	sort(v.begin(), v.end());
	for(int i=0; i<N; i++){
		bool tf = false;
		for(int j : vt){
			if(v[i] % j == 0){
				tf = true;
				break;
			}		}
		if(tf)	continue;
		vt.pb(v[i]);
	}
	printf("%d", vt.size());
	return 0;
}