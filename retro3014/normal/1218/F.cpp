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

int N, A, K;
vector<int> v;
priority_queue<int, vector<int>, greater<int> > pq;

ll ans;

int main(){
	scanf("%d%d", &N, &K);
	for(int i=0; i<N; i++){
		int x; scanf("%d", &x);
		v.pb(x);
	}	
	scanf("%d", &A);
	for(int i=0; i<N; i++){
		int x; scanf("%d", &x);
		pq.push(x);
		while(K<v[i] && !pq.empty()){
			ans+=pq.top(); pq.pop();
			K+=A;
		}
		if(K<v[i] && pq.empty()){
			printf("-1");
			return 0;
		}
	}
	printf("%lld\n", ans);
	return 0;
}