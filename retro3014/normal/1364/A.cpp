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

int T, N, X;
int sum[MAX_N+1];

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &N, &X);
		int t = 0;
		int ans = -1;
		for(int i=1; i<=N; i++){
			scanf("%d", &sum[i]);
			sum[i]+=sum[i-1];
			if(sum[i]%X==0){
				if(t!=0){
					ans = max(ans, i-t);
				}
			}else{
				ans = max(ans, i);
				if(t==0)	t = i;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}