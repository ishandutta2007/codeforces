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

int N, M;
vector<int> v;
vector<int> ans;

int main(){
	scanf("%d%d", &N, &M);
	bool tf = true;
	for(int i=1; i<=M; i++){
		int l; scanf("%d", &l);
		if(l>N-i+1){
			tf = false;
		}
		v.pb(l);
	}
	if(!tf){
		printf("-1");
		return 0;
	}
	int n = N;
	int pos;
	while(!v.empty()){
		int x = v.back(); v.pop_back();
		pos = ((int)v.size())+1;
		pos = max(pos, n-x+1);
		ans.pb(pos);
		n = pos-1;
	}
	if(n!=0){
		printf("-1");
		return 0;
	}
	while(!ans.empty()){
		printf("%d ", ans.back());
		ans.pop_back();
	}
	return 0;
}