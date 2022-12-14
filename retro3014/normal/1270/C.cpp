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
int N;
ll S, X;
vector<ll> ans;

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		while(!ans.empty())	{
			ans.pop_back();
		}
		S = X = 0;
		for(int i=0; i<N; i++){
			int x; scanf("%d", &x);
			S += (ll)x;
			X = (X ^ (ll)x);
		}
		if(X!=0){
			ans.pb(X);
			S += X;
			X = 0;
		}
		ans.pb(S);
		printf("%d\n", (int)ans.size());
		for(int i=0; i<ans.size(); i++){
			printf("%lld ", ans[i]);
		}printf("\n");
	}
	return 0;
}