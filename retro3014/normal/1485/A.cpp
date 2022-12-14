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

int T, A, B;

int calc(int x, int y){
	if(y==1)	return INF;
	int ret = 0;
	while(x>0){
		x/=y;
		ret++;
	}
	return ret;
}

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &A, &B);
		int ans = INF;
		for(int i=0; i<=40; i++){
			ans = min(ans, i+calc(A, B+i));
		}
		printf("%d\n", ans);
	}
	return 0;
}