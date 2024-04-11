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

int N;
vector<pii> gp[MAX_N+1];
int ans[MAX_N+1];
int main(){
	scanf("%d", &N);
	for(int i=1; i<N; i++){
		int a, b; scanf("%d%d", &a, &b);
		gp[a].pb({b, i}); gp[b].pb({a, i});
	}
	for(int i=1; i<=N; i++){
		if(gp[i].size()>2){
			ans[gp[i][0].second] = 0;
			ans[gp[i][1].second] = 1;
			ans[gp[i][2].second] = 2;
			int cnt = 2;
			for(int j=1; j<N; j++){
				bool tf = true;
				for(int k=0; k<3; k++){
					if(j==gp[i][k].second)	{
						tf = false;
						break;
					}
				}
				if(tf){
					ans[j] = ++ cnt;
				}
			}
			for(int j=1; j<N; j++){
				printf("%d\n", ans[j]);
			}
			return 0;
		}
	}
	for(int i=1; i<N; i++){
		printf("%d\n", i-1);
	}
	return 0;
}