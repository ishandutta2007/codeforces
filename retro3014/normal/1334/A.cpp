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

int T, N;
int a, b, pa, pb;

int main(){
	scanf("%d", &T);
	while(T--){
		pa = 0, pb = 0;
		bool tf = true;
		scanf("%d", &N);
		for(int i=1; i<=N; i++){
			scanf("%d%d", &a, &b);
			if(a<pa){
				tf = false;
			}
			if(b<pb){
				tf = false;
			}
			if((a-pa)<(b-pb)){
				tf = false;
			}
			pa = a;
			pb = b;
		}
		if(tf){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}