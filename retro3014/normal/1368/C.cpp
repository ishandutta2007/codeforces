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

vector<pii> vt;

int main(){
	scanf("%d", &N);
	vt.pb({0, 0});
	vt.pb({1, 0});
	vt.pb({1, 1});
	vt.pb({0, 1});
	for(int i=1; i<=N; i++){
		vt.pb({i, i+1});
		vt.pb({i+1, i});
		vt.pb({i+1, i+1});

	}
	printf("%d\n", (int)vt.size());
	for(int i=0; i<vt.size(); i++){
		printf("%d %d\n", vt[i].first, vt[i].second);
	}
	return 0;
}