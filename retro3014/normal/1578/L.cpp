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
const int MAX_N = 1000;

int T;
int N;
vector<int> v1, v2;

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		v1.clear(); v2.clear();
		for(int i=0; i<N; i++){
			int x; scanf("%d", &x); v1.pb(x);
		}
		for(int i=0; i<N; i++){
			int x; scanf("%d", &x);v2.pb(x);
		}
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		bool tf = true;
		for(int i=0 ;i<N; i++){
			if(v1[i]==v2[i] || v1[i]+1==v2[i])	continue;
			tf = false;
			break;
		}
		if(tf){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}