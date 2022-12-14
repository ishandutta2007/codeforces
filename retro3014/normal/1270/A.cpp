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

int N, T;
int K1, K2;


int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%d%d", &N, &K1, &K2);
		int mx1 = 0, mx2 = 0;
		for(int i=0; i<K1; i++){
			int x; scanf("%d", &x);
			mx1 = max(mx1, x);
		}
		for(int i=0; i<K2; i++){
			int x; scanf("%d", &x);
			mx2 = max(mx2, x);
		}
		if(mx1>mx2){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}