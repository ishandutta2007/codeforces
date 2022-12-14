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
const int INF = 1e9;
const ll INFLL = 1e18;
const int MAX_N = 15;
const int MAX_K = (1<<16);
 
int K;
vector<int> n;
vector<ll> v[MAX_N+1];
ll SUM = 0;
ll c[MAX_N+1];
map<ll, ll> group, nxt;
set<ll> st;
vector<ll> vt;
 
bool vst[MAX_N+1];
vector<int> state;
bool dp[MAX_K+1];
int from[MAX_K+1];
pii ans[MAX_N+1];
pii answer[MAX_N+1];
bool chk[MAX_K+1];
 
void dfs(int x){
	//cout<<x<<endl;
	for(int i=0; i<K; i++){
		vst[i] = false;
	}
	ll now = (ll)x;
	int s = 0;
	while(1){
		//cout<<now<<endl;
		if(vst[group[now]]){
			return;
		}
		s += (1<<group[now]);
		vst[group[now]] = true;
		if(nxt[now]==x){
			if(chk[s]==false){
				state.pb(s);
				chk[s] = true;
			}
			return;
		}
		if(st.find(nxt[now])==st.end()){
			return;
		}
		//cout<<now<<" "<<nxt[now]<<endl;
		now = nxt[now];
	}
}
 
int calc(int x){
	for(int i=0; i<K; i++){
		vst[i] = false;
	}
	ll now = (ll)x;
	int s = 0;
	while(1){
		if(vst[group[now]] && now==x){
			return s;
		}
		if(vst[group[now]]){
			return -1;
		}
		s += (1<<group[now]);
		vst[group[now]] = true;
		if(st.find(nxt[now])==st.end()){
			return -1;
		}
		ans[group[nxt[now]]] = {nxt[now], group[now]};
		now = nxt[now];
	}
}
 
 
int main(){
	scanf("%d", &K);
	for(int i=0; i<K; i++){
		int x; scanf("%d", &x);
		n.pb(x);
		for(int j=0; j<n[i]; j++){
			scanf("%d", &x);
			v[i].pb((ll)x);
			SUM += (ll)x;
			c[i] += (ll)x;
			group[x] = i;
			st.insert((ll)x);
		}
	}
	if(SUM%K!=0){
		printf("No");
		return 0;
	}
	SUM/=K;
	for(int i=0; i<K; i++){
		c[i] = SUM - c[i];
	}
	for(int i=0; i<K; i++){
		for(int j=0; j<n[i]; j++){
			nxt[v[i][j]] = v[i][j] + c[i];
		}
	}
	for(set<ll>::iterator it = st.begin(); it!=st.end(); it++){
		dfs((*it));
	}
	dp[0] = true;
	for(int i=0; i<(1<<K); i++){
		if(dp[i]){
			for(int j : state){
				if((i & j)==0 && !dp[i+j]){
					dp[i+j] = true;
					from[i+j] = i;
				}
			}
		}
	}
	/*for(int i=0; i<state.size(); i++){
		cout<<state[i]<<" ";
	}*/
	if(dp[(1<<K)-1]){
		int t = (1<<K)-1;
		while(t!=0){
			int d = t - from[t];
			for(int i=0; i<K; i++){
				if(((1<<i) & d) != 0){
					for(int j=0; j<v[i].size(); j++){
						if(d==calc(v[i][j])){
							for(int k=0; k<K; k++){
								if(((1<<k) & d )!= 0){
									answer[k] = ans[k];
								}
							}
							break;
						}
					}
					break;
				} 
			}
			t = from[t];
		}
		printf("Yes\n");
		for(int i=0; i<K; i++){
			printf("%d %d\n", answer[i].first, answer[i].second+1);
		}
	}
	else{
		printf("No");
	}
	return 0;
}