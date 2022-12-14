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

int N, M;
vector<int> vt;
bool chk[MAX_N+1];
bool tf = false;

int zero(int x){
	return (x>0)?x:-x;
}

int main(){
	scanf("%d%d", &N, &M);
	for(int i=1; i<=N; i++){
		int x;
		scanf("%d",&x);
		vt.pb(x);
		x = (x % M);
		if(chk[x]){
			tf = true;
		}
		chk[x] = true;
	}
	if(tf){
		printf("0");
		return 0;
	}
	int ans = 1;
	for(int i=0; i<vt.size(); i++){
		for(int j=i+1; j<vt.size(); j++){
			ans = (ans * (zero(vt[i]-vt[j])%M)) % M;
		}
	}
	printf("%d", ans);
	return 0;
}