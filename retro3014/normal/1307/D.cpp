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

int N, M, K;
int d1[MAX_N+1], d2[MAX_N+1];
vector<int> gp[MAX_N+1];
vector<int> v;

deque<int> dq;

void bfs(int x){
	d1[x] = 0;
	for(int i=2; i<=N; i++)	d1[i] = INF;
	dq.pb(x);
	while(!dq.empty()){
		int now = dq.front(); dq.pop_front();
		for(int j : gp[now]){
			if(d1[j]==INF){
				d1[j] = d1[now]+1;
				dq.pb(j);
			}
		}
	}
}

void bfs2(int x){
	d2[x] = 0;
	for(int i=1; i<N; i++)	d2[i] = INF;
	dq.pb(x);
	while(!dq.empty()){
		int now = dq.front(); dq.pop_front();
		for(int j : gp[now]){
			if(d2[j]==INF){
				d2[j] = d2[now]+1;
				dq.pb(j);
			}
		}
	}
}

bool sf(int x, int y){
	return d1[x]<d1[y];
}

int main(){
	scanf("%d%d%d", &N, &M, &K);
	for(int i=1; i<=K; i++){
		int x; scanf("%d", &x);
		v.pb(x);
	}
	for(int i=1; i<=M; i++){
		int a, b; scanf("%d%d", &a, &b);
		gp[a].pb(b); gp[b].pb(a);
	}
	bfs(1);
	bfs2(N);
	sort(v.begin(), v.end(), sf);
	int ans = 0;
	int mn = -INF;
	for(int i=0; i<v.size(); i++){
		if(i<v.size()-1 && (d1[v[i]]==d1[v[i+1]] || d1[v[i]]+1==d1[v[i+1]])){
			printf("%d", d1[N]);
			return 0;
		}
		ans = max(ans, min(d1[N], d2[v[i]] + 1 + mn));
		mn = max(mn, d1[v[i]]);
	}
	printf("%d", ans);
	return 0;
}