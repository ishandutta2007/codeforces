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

int N, M, K;
vector<int> v;

int main(){
	scanf("%d%d%d", &N, &M, &K);
	for(int i=0; i<N; i++){
		int x; scanf("%d", &x); v.push_back(x);
	}
	sort(v.begin(), v.end());
	int t = M / (K+1);
	ll ans = 0;
	ans += (ll)v[v.size()-2] * (ll)t;
	ans += (ll)v.back() * (ll)(M-t);
	printf("%lld", ans);
	return 0;
}