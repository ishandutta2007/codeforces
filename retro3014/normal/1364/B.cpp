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
const int MAX_N = 20000;

int T;
int N;
vector<int> ans;

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		while(!ans.empty())	ans.pop_back();
		for(int i=1; i<=N; i++){
			int x; scanf("%d", &x);
			if(ans.size()<=1){
				ans.pb(x);
			}else{
				if((ans.back()>ans[(int)ans.size()-2]) == (x>ans.back())){
					ans.pop_back();
				}
				ans.pb(x);
			}
		}
		printf("%d\n", (int)ans.size());
		for(int i : ans)	printf("%d ", i);
		printf("\n");
	}
	return 0;
}