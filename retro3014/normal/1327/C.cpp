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

int N, M, K;
vector<pii> s, e;

string str;

int main(){
	scanf("%d%d%d", &N, &M, &K);
	for(int i=1; i<=K; i++){
		int a, b; scanf("%d%d", &a, &b);
		s.pb({a, b});
	}
	for(int i=1; i<=K; i++){
		int a, b; scanf("%d%d", &a, &b);
		e.pb({a, b});
	}
	for(int i=1; i<N; i++){
		str.pb('U');
	}
	for(int i=1; i<M; i++){
		str.pb('L');
	}
	for(int i=1; i<=N; i++){
		if(i!=1){
			str.pb('D');
		}
		for(int j=1; j<M; j++){
			if(i%2==1){
				str.pb('R');
			}else{
				str.pb('L');
			}
		}
	}
	printf("%d\n", (int)str.size());
	cout<<str;
	return 0;
}