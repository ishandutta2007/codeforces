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
vector<pii>  vt;

int main(){
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		int a, b; scanf("%d%d", &a, &b);
		vt.pb({a, b});
	}	
	if(N%2==1){
		printf("NO");
		return 0;
	}
	for(int i=0; i<N/2; i++){
		int i1 = i, i2 = i+N/2;
		if(vt[i1+1].first-vt[i1].first!=vt[i2].first-vt[(i2+1)%N].first){
			printf("NO");
			return 0;
		}
		if(vt[i1+1].second-vt[i1].second!=vt[i2].second-vt[(i2+1)%N].second){
			printf("NO");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}