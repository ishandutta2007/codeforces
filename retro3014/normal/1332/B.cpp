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

vector<int> prime;
vector<int> v[100];
int T;
int N;
int ans[MAX_N+1];

int main(){
	for(int i=2; i*i<=1000; i++){
		bool tf = true;
		for(int j : prime){
			if(i%j==0)	{
				tf = false;
				break;
			}
		}
		if(tf)	prime.pb(i);
	}
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		for(int j=0; j<prime.size(); j++){
			if(!v[j].empty())	v[j].pop_back();
		}
		for(int i=1; i<=N; i++){
			int x;
			scanf("%d", &x);
			for(int j=0; j<prime.size(); j++){
				if(x%prime[j]==0){
					v[j].pb(i);
					break;
				}
			}
		}
		int cnt = 0;
		for(int i=0; i<prime.size(); i++){
			if(!v[i].empty()){
				++cnt;
				while(!v[i].empty()){
					ans[v[i].back()] = cnt;
					v[i].pop_back();
				}
			}
		}
		printf("%d\n", cnt);
		for(int i=1; i<=N; i++){
			printf("%d ", ans[i]);
		}
		printf("\n");
	}
	return 0;
}