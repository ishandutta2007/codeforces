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

const int MAX_N = 300000;

int N;
int c[MAX_N+1];
vector<int> gp[MAX_N+1];
int R, B;
int ans;
int p[MAX_N+1];
pii cnt[MAX_N+1];

void dfs(int x){
	for(auto i : gp[x]){
		if(i==p[x])	continue;
		p[i] = x;
		dfs(i);
		cnt[x].first+=cnt[i].first; cnt[x].second+=cnt[i].second;
	}
	if(c[x]==1)	cnt[x].first++;
	else if(c[x]==2)	cnt[x].second++;
	if(x==1)	return;
	if(cnt[x].first==R && cnt[x].second==0)	ans++;
	else if(cnt[x].first==0 && cnt[x].second==B)	ans++;
}

int main(){
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		scanf("%d", &c[i]);
		if(c[i]==1)	R++; 
		else if(c[i]==2)	B++;
	}
	for(int i=0; i<N-1; i++){
		int a, b; scanf("%d%d", &a, &b);
		gp[a].push_back(b); gp[b].push_back(a);
	}
	dfs(1);
	cout<<ans;
	return 0;
}