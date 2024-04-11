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

int T, N;
vector<int> X, Y;

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		while(!X.empty())	X.pop_back();
		while(!Y.empty())	Y.pop_back();
		for(int i=0; i<N; i++){
			int x; scanf("%d", &x);
			X.pb(x);
		}
		for(int i=0; i<N; i++){
			int x; scanf("%d", &x);
			Y.pb(x);
		}
		sort(X.begin(), X.end());
		sort(Y.begin(), Y.end());
		for(int i=0; i<N; i++){
			printf("%d ", X[i]);
		}
		printf("\n");
		for(int i=0; i<N; i++){
			printf("%d ", Y[i]);
		}
		printf("\n");
	}
	return 0;
}