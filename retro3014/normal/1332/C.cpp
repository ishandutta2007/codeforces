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
const int MAX_T = 30;
int T, N, K;
string str;
vector<int> gp[MAX_N+1];
bool vst[MAX_N+1];
int cnt[MAX_T+1];
int ans = 0;

void dfs(int x){
	vst[x] = true;
	cnt[str[x-1]-'a']++;
	for(int j : gp[x]){
		if(!vst[j]){
			dfs(j);
		}
	}
}

int main(){
	scanf("%d", &T);
	while(T--){
		ans = 0;
		scanf("%d%d", &N, &K);
		cin>>str;
		for(int i=1; i<=N; i++){
			while(!gp[i].empty())	gp[i].pop_back();
			vst[i] = false;
		}
		for(int i=1; i<=N/2; i++){
			gp[i].pb(N+1-i);
			gp[N+1-i].pb(i);
		}
		for(int i=1; i<=N-K; i++){
			gp[i].pb(K+i);
			gp[K+i].pb(i);
		}
		for(int i=1; i<=N; i++){
			if(vst[i]==false){
				for(int j=0; j<=26; j++){
					cnt[j]=0;
				}
				dfs(i);
				int mx = 0;
				for(int j=0; j<=26; j++){
					ans+=cnt[j];
					mx = max(mx, cnt[j]);
				}
				ans-=mx;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}