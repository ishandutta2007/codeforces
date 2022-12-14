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
vector<int> gp[MAX_N+1];
bool chk[MAX_N+1];

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		for(int i=1; i<=N; i++){
			chk[i] = false;
		}
		int a = 0, b = 0;
		for(int i=1; i<=N; i++){
			int sz; scanf("%d", &sz);
			bool tf = true;
			while(sz--){
				int x; scanf("%d", &x);
				if(chk[x]==false && tf){
					chk[x] = true;
					tf = false;
				}
			}
			if(tf){
				a = i;
			}
		}
		for(int i=1; i<=N; i++){
			if(chk[i]==false){
				b = i;
				break;
			}
		}
		if(a==0){
			printf("OPTIMAL\n");
		}else{
			printf("IMPROVE\n");
			printf("%d %d\n", a, b);
		}
	}
	return 0;
}