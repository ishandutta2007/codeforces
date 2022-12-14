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

int T;
int N;
vector<int> v;
int idx[MAX_N+1];

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		for(int i=1; i<=N; i++){
			int x; scanf("%d", &x);
			v.pb(x);
			idx[x] = i;
		}
		int mn = N+1;
		int cnt = 0;
		bool tf = true;
		for(int i=1; i<=N; i++){
			if(mn==N-cnt+1){
				mn = min(mn, idx[i]);
			}else{
				if(idx[i]!=idx[i-1]+1){
					tf = false;
					break;
				}
			}
			cnt++;
		}
		if(tf){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}