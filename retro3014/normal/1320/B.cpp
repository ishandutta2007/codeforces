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
vector<int> gp[MAX_N+1], rgp[MAX_N+1];
vector<int> v;
int cnt[MAX_N+1], dist[MAX_N+1];
deque<int> dq;

void bfs(int x){
	for(int i=1; i<=N; i++){
		dist[i] = INF;
	}
	dist[x] = 0;
	dq.pb(x);
	while(!dq.empty()){
		int now = dq.front(); dq.pop_front();
		for(int i : rgp[now]){
			if(dist[i]==INF){
				dist[i] = dist[now]+1;
				cnt[i]++;
				dq.pb(i);
			}else if(dist[i]==dist[now]+1){
				cnt[i]++;
			}
		}
	}
}

int main(){
	scanf("%d%d", &N, &M);
	for(int i=1; i<=M; i++){
		int a, b; scanf("%d%d", &a, &b);
		gp[a].pb(b); rgp[b].pb(a);
	}
	scanf("%d", &K);
	for(int i=1; i<=K; i++){
		int x; scanf("%d", &x);
		v.pb(x);
	}
	bfs(v.back());
	int ans1 = 0, ans2 = 0;
	for(int i=0; i<v.size()-1; i++){
		if(dist[v[i]]!=dist[v[i+1]]+1){
			ans1++;
			ans2++;
		}else if(cnt[v[i]]>1){
			ans2++;
		}
	}
	printf("%d %d", ans1, ans2);
	return 0;
}