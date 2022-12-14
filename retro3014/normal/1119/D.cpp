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

int N, Q;
vector<ll> v;
struct Query{
	Query(ll num, int idx, ll ans) : num(num), idx(idx), ans(ans) {}
	ll num;
	int idx;
	ll ans;
	bool operator <(const Query &a)const{
		return idx<a.idx;
	}
};
vector<Query> q;
bool sf1(Query a, Query b){
	return a.num<b.num;
}

vector<ll> d;

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		ll x;
		scanf("%lld", &x);
		v.pb(x);
	}
	sort(v.begin(), v.end());
	for(int i=1; i<N; i++){
		d.pb(v[i]-v[i-1]);
	}
	sort(d.begin(), d.end());
	scanf("%d", &Q);
	for(int i=0; i<Q; i++){
		ll x, y;
		scanf("%lld %lld", &x, &y);
		q.pb({y-x+1, i, 0});
	}
	sort(q.begin(), q.end(), sf1);
	int idx = 0;
	ll cnt = 0;
	ll pl = (ll)N;
	ll prv = 0;
	for(int i=0; i<q.size(); i++){
		while(idx<d.size() && d[idx]<q[i].num){
			cnt += (d[idx]-prv) * pl;
			prv = d[idx];
			pl--;
			idx++;
		}
		cnt += (q[i].num-prv) * pl;
		prv = q[i].num;
		q[i].ans = cnt;
	}
	sort(q.begin(), q.end());
	for(int i=0; i<q.size(); i++){
		printf("%lld ", q[i].ans);
	}
	return 0;
}