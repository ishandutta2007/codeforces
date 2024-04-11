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
const int MAX_N = 200000;

int T;
int N, M;
vector<int> gp[MAX_N+1];

int c1[MAX_N+1], c2[MAX_N+1];
vector<int> ans;

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &N, &M);
		for(int i=1; i<=M; i++){
			int a, b; scanf("%d%d", &a, &b);
			gp[a].pb(b);
		}
		for(int i=1; i<=N; i++)	c1[i] = c2[i] = false;
		for(int i=1; i<=N; i++){
			if(!c1[i] && !c2[i]){
				for(int j : gp[i])	c1[j] = true;
			}else{
				if(!c2[i]){
					for(int j : gp[i])	c2[j] = true;
				}else{
					ans.pb(i);
				}
			}
		}
		printf("%d\n", (int)ans.size());
		for(int i : ans){
			printf("%d ", i);
		}printf("\n");
		while(!ans.empty())	ans.pop_back();
		for(int i=1; i<=N; i++){
			while(!gp[i].empty())	gp[i].pop_back();
		}
	}


	
	return 0;
}