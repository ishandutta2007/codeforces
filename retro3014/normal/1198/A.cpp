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


const int MAX_N = 400000;

int N, I, M;
vector<int> vt;
map<int, int> mp;
vector<int> v;
int cnt[MAX_N+1];

int main(){
	scanf("%d%d", &N, &I);
	M = N;
	for(int i=0; i<N; i++){
		int x; scanf("%d", &x);
		if(mp[x]==0){
			vt.pb(x);
		}
		mp[x]++;
	}
	sort(vt.begin(), vt.end());
	N = vt.size();
	for(int i=1; i<=vt.size(); i++){
		cnt[i] = cnt[i-1] + mp[vt[i-1]];
		//cout<<cnt[i]<<endl;
	}
	I*=8; I/=M;
	ll two = 1;
	//cout<<I<<endl;
	while(two<(ll)vt.size() && I>0){
		I--;
		two*=2;
	}
	two = min((ll)N, two);
	//cout<<two<<endl;
	int ans = 0;
	for(int i=two; i<=N; i++){
		ans = max(ans, cnt[i] - cnt[i-two]);
	}
	cout<<M - ans;

	return 0;
}