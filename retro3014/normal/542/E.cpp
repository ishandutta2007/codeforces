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

int N, M;
vector<int> gp[MAX_N+1];
int c[MAX_N+1];
bool vst[MAX_N+1];
bool tf = true;

void dfs(int x){
	vst[x] = true;
	for(int i : gp[x]){
		if(!vst[i]){
			c[i] = 1 - c[x];
			dfs(i);
		}else{
			if(c[i]==c[x]){
				tf = false;
			}
		}
	}
}

int ans;
vector<int> v;

void dfs2(int x){
	vst[x] = true;
	v.pb(x);
	for(int i : gp[x]){
		if(!vst[i]){
			dfs2(i);
		}
	}
}

deque<pii> dq;
	

int solve(int x){
	int ret = 0;
	dfs2(x);
	for(int i : v){
		int mx = 0;
		for(int j : v){
			vst[j] = false;
		}
		dq.pb({i, 0});
		vst[i] = true;
		while(!dq.empty()){
			pii now = dq.front(); dq.pop_front();
			mx = max(mx, now.second);
			for(int j : gp[now.first]){
				if(!vst[j]){
					vst[j] = true;
					dq.pb({j, now.second+1});
				}
			}
		}
		ret = max(mx, ret);
		//cout<<i<<" "<<mx<<endl;
	}
	while(!v.empty()){
		v.pop_back();
	}
	return ret;
}

int main(){
	cin>>N>>M;
	for(int i=1; i<=M; i++){
		int a, b;
		scanf("%d%d", &a, &b);
		gp[a].pb(b); gp[b].pb(a);
	}
	for(int i=1; i<=N; i++){
		if(!vst[i]){
			dfs(i);
		}
	}
	if(!tf){
		printf("-1");
		return 0;
	}
	for(int i=1; i<=N; i++){
		vst[i] = false;
	}
	for(int i=1; i<=N; i++){
		if(!vst[i]){
			ans += solve(i);
		}
	}
	cout<<ans;
	return 0;
}