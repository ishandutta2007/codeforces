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

int N;
vector<int> v;
int ans = 0;
vector<pii> vt;

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int x; scanf("%d", &x); v.push_back(x);
		vt.push_back({0, 0});
	}
	vt.push_back({0, 0});
	for(int i=N-1; i>=0; i--){
		pii now = {0, 0};
		now.first = vt[i+1].second; now.second = vt[i+1].first;
		now.first+=v[i];
		vt[i] = now;
	}
	pii now = {0, 0};
	for(int i=0; i<N; i++){
		if(now.second + vt[i+1].first == now.first + vt[i+1].second)	ans++;
		int tmp = now.second; now.second = now.first; now.first = tmp;
		now.first+=v[i];
	}
	printf("%d", ans);
	return 0;
}