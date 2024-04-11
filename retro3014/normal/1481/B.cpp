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
const int MAX_N = 100;

int T;
int N, K;
int h[MAX_N+1];

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &N, &K);
		for(int i=1; i<=N; i++){
			scanf("%d", &h[i]);
		}
		bool tf = true;
		int ans = 0;
		for(int i=1; i<=K; i++){
			int pos = 1;
			while(pos!=N){
				if(h[pos]>=h[pos+1])	pos++;
				else	break;
			}
			if(pos==N){
				tf = false;
				printf("-1\n");
				break;
			}else{
				ans = pos;
				h[pos]++;
			}
		}
		if(tf){
			printf("%d\n", ans);
		}
	}
	return 0;
}