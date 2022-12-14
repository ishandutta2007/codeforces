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
const int MAX_K = 30;

int qor(int x, int y){
	printf("or %d %d\n", x, y);
	fflush(stdout);
	scanf("%d", &x);
	return x;
}

int qand(int x, int y){
	printf("and %d %d\n", x, y);
	fflush(stdout);
	scanf("%d", &x);
	return x;
}

int N, K;

vector<int> vand, vor;
int tand, tor;
int M;
vector<int> ans;

int main(){
	scanf("%d%d", &N, &K);
	for(int i=2; i<=N; i++){
		vand.pb(qand(1, i));
		vor.pb(qor(1, i));
	}
	tand = qand(2, 3);
	for(int i=0; i<=MAX_K; i++){
		bool tf = false;
		for(int j=0; j<vand.size(); j++){
			if((vand[j] & (1<<i)) != 0){
				M += (1<<i);
				tf = true;
				break;
			}else if((vor[j] & (1<<i)) == 0){
				tf = true;
				break;
			}
		}
		if(!tf){
			if((tand & (1<<i)) == 0){
				M+=(1<<i);
			}

		}
	}
	ans.pb(M);
	for(int i=0; i<vand.size(); i++){
		int x = vor[i]-vand[i];
		x = (x ^ M);
		ans.pb(x);
	}

	sort(ans.begin(), ans.end());
	printf("finish %d\n", ans[K-1]);
	fflush(stdout);
	return 0;
}