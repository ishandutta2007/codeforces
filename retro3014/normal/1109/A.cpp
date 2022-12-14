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

map<int, int> mp1, mp2;
int N;
vector<int> v;
ll ans;

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int x;
		scanf("%d", &x);v.push_back(x);
	}
	int k = 0;
	mp2[0] = 1;
	for(int i=0; i<N; i++){
		k = (k^v[i]);
		if(i%2==0){
			ans += (ll)mp1[k];
			mp1[k]++;
		}else{
			ans += (ll)mp2[k];
			mp2[k]++;
		}
	}
	printf("%lld", ans);
	return 0;
}