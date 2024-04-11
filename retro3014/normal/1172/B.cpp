#include <bits/stdc++.h>

#define pb push_back
#define all(v) ((v).begin(), (v).end())
#define sortv(v) sort(all(v))
#define sz(v) ((int)(v).size())
#define uniqv(v) (v).erase(unique(all(v)), (v).end())
#define umax(a, b) (a)=max((a), (b))
#define umin(a, b) (a)=min((a), (b))
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define rep(i,n) FOR(i,1,n)
#define rep0(i,n) FOR(i,0,(int)(n)-1)
#define FI first
#define SE second
#define INF 2000000000
#define INFLL 1000000000000000000LL


using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


const int MAX_N = 200000;
const ll DIV = 998244353;


int N;
vector<int> gp[MAX_N+1];
int p[MAX_N+1];
int num[MAX_N+1];
int cnt[MAX_N+1];
ll pac[MAX_N+1];
ll ans = 1;

void dfs(int x){
	cnt[x] = 0;
	num[x] = 1;
	for(int i=0; i<gp[x].size(); i++){
		if(gp[x][i]==p[x])	continue;
		p[gp[x][i]] = x;
		cnt[x]++;
		dfs(gp[x][i]);
		num[x]+=num[gp[x][i]];
	}
	if(x!=1){
		ans = (ans * pac[cnt[x]+1])%DIV;
	}else{
		ans = (ans * pac[cnt[x]])%DIV;
	}
}


int main(){
	scanf("%d", &N);
	pac[1] = 1;
	ans = N;
	for(ll i=2; i<=MAX_N; i++){
		pac[i] = (pac[i-1] * i)%DIV;
	}
	for(int i=0; i<N-1; i++){
		int a ,b;
		scanf("%d%d", &a, &b);
		gp[a].pb(b); gp[b].pb(a);
	}
	dfs(1);
	cout<<ans;
	return 0;
}