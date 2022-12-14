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
const int MAX_N = 1000000;

int T;
int N;
vector<int> v;
bool chk[MAX_N+1];
vector<int> ans;

int main(){
	scanf("%d", &T);
	while(T--){
		while(!v.empty())	v.pop_back();
		scanf("%d", &N);
		v.pb(0);
		for(int i=1; i<=N; i++){
			chk[i] = false;
			int x; scanf("%d", &x);
			v.pb(i-x);
		}
		bool tf = false;
		for(int i=1; i<=N; i++){
			if(v[i]==i){
				printf("1\n%d\n", i);
				tf = true;
				break;
			}
		}
		if(tf)	continue;
		int now = 1;
		while(1){
			if(chk[now]){
				break;
			}
			chk[now] = true;
			now = v[now];
		}
		int t = now;
		ans.pb(t);
		t = v[t];
		while(t!=now){
			ans.pb(t);
			t = v[t];
		}
		printf("%d\n", (int)ans.size());
		for(int i=0; i<ans.size(); i++){
			printf("%d ", ans[i]);
		}
		printf("\n");
		while(!ans.empty())	ans.pop_back();
	}
	return 0;
}