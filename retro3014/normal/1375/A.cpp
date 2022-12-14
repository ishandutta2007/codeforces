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

int N;
int T;
vector<int> v;

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		while(!v.empty())	v.pop_back();
		for(int i=1; i<=N; i++){
			int x; scanf("%d", &x);
			if(i%2){
				if(x>0)	x*=-1;
			}else{
				if(x<0)	x*=-1;
			}
			v.pb(x);
		}
		for(int i=0; i<v.size(); i++){
			printf("%d ", v[i]);
		}printf("\n");
	}
	return 0;
}