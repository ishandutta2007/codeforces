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
const int MAX_N = 3000;

int N, M;
vector<int> gp[MAX_N+1];
int dist[MAX_N+1][MAX_N+1];

deque<int> dq;
bool vst[MAX_N+1];

void bfs(int x){
	for(int i=1; i<=N; i++)	{
		vst[i] = false;
		dist[x][i] = INF;
	}
	dist[x][x] = 0;
	dq.pb(x);
	while(!dq.empty()){
		int now = dq.front(); dq.pop_front();
		if(vst[now])	return;
		vst[now] = true;
		for(int i : gp[now]){
			if(dist[x][i]>dist[x][now]+1){
				dist[x][i] = dist[x][now]+1;
				dq.pb(i);
			}
		}
	}
	return;
}

int ans;
int s1, e1, l1, s2, e2, l2;
int main(){
	scanf("%d%d", &N, &M);
	ans = M+1;
	for(int i=1; i<=M; i++){
		int a, b;
		scanf("%d%d", &a, &b); gp[a].pb(b); gp[b].pb(a);
	}
	for(int i=1; i<=N; i++){
		bfs(i);
	}
	scanf("%d%d%d%d%d%d", &s1, &e1, &l1, &s2, &e2, &l2);
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			if(dist[s1][i] + dist[i][j] + dist[j][e1] > l1)	continue;
			if(dist[s2][i] + dist[i][j] + dist[j][e2] > l2)	continue;
			//cout<<i<<" "<<j<<" "<<dist[s1][i] + dist[i][j] + dist[j][e1] + dist[s2][i] + dist[j][e2]<<endl;
			ans = min(ans, dist[s1][i] + dist[i][j] + dist[j][e1] + dist[s2][i] + dist[j][e2]);
		}
		for(int j=1; j<=N; j++){
			if(dist[s1][i] + dist[i][j] + dist[j][e1] > l1)	continue;
			if(dist[s2][j] + dist[i][j] + dist[i][e2] > l2)	continue;
			//cout<<i<<" "<<j<<" "<<dist[s1][i] + dist[i][j] + dist[j][e1] + dist[s2][i] + dist[j][e2]<<endl;
			ans = min(ans, dist[s1][i] + dist[i][j] + dist[j][e1] + dist[s2][j] + dist[i][e2]);
		}
	}
	if(dist[s1][e1]<=l1 && dist[s2][e2]<=l2) ans = min(ans, dist[s1][e1] + dist[s2][e2]);
	cout<<M-ans;
	return 0;
}