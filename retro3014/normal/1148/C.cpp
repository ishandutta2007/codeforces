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

vector<int> v;
int N;
int idx[MAX_N+1];
vector<pii> ans;

int swp(int x, int y){
	ans.pb({x, y});
	int tmp = idx[v[x]]; idx[v[x]] = idx[v[y]]; idx[v[y]] = tmp;
	tmp = v[x]; v[x] = v[y]; v[y] = tmp;
}

int main(){
	scanf("%d", &N);	
	v.pb(0);
	for(int i=1; i<=N; i++){
		int x; scanf("%d", &x);
		v.pb(x);
		idx[x] = i;
	}
	for(int i=2; i<=N/2; i++){
		int t = idx[i];
		if(t<=N/2){
			swp(t, N);
			swp(N, i);
		}else{
			swp(1, t);
			swp(1, N);
			swp(N, i);
		}
	}
	for(int i=N/2+1; i<N; i++){
		int t = idx[i];
		if(t<=N/2){
			swp(t, N);
			swp(1, N);
			swp(1, i);
		}else{
			swp(t, 1);
			swp(1, i);
		}
	}
	if(idx[1]!=1){
		swp(1, N);
	}
	printf("%d\n", ans.size());
	for(int i=0; i<ans.size(); i++){
		printf("%d %d\n", ans[i].first, ans[i].second);
	}
	return 0;
}