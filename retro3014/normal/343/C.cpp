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

int N, M;
vector<ll> v, vt;

bool chk(ll x){
	int idx = 0;
	ll r = 0;
	for(int i=0; i<N; i++){
		if(vt[idx]<v[i]){
			if(v[i]-x>vt[idx]){
				return false;
			}
			r = max(r, v[i] + (x - (v[i] - vt[idx]))/2);
			r = max(r, vt[idx] + (x - (v[i] - vt[idx])));
			while(r>=vt[idx]){
				idx++;
				if(idx==M)	return true;
			}
		}else{
			r = max(r, v[i] + x);
			while(r>=vt[idx]){
				idx++;
				if(idx==M)	return true;
			}
		}
	}
	return false;
}

int main(){
	cin>>N>>M;
	for(int i=0; i<N; i++){
		ll x;
		cin>>x; v.pb(x);
	}for(int i=0; i<M; i++){
		ll x;
		cin>>x; vt.pb(x);
	}
	ll s = 0, e = 20000000000, m;
	while(s<e){
		m = (s+e)/2;
		if(chk(m)){
			e = m;
		}else{
			s = m+1;
		}
	}
	cout<<s;
	return 0;
}