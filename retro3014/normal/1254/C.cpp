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
const int MAX_N = 1;

int N;
vector<int> v1, v2;

ll ask1(int x, int y, int z){
	printf("1 %d %d %d\n", x, y, z);
	fflush(stdout);
	ll r; scanf("%lld", &r);
	return r;
}

int ask2(int x, int y, int z){
	printf("2 %d %d %d\n", x, y, z);
	fflush(stdout);
	int r; scanf("%d", &r);
	return r;
}

vector<pll> vt;

int main(){
	scanf("%d", &N);
	int l = 2;
	for(int i=3; i<=N; i++){
		if(ask2(1, l, i)==-1){
			l = i;
		}
	}
	v1.pb(1); v1.pb(l);
	for(int i=2; i<=N; i++){
		if(i==l)	continue;
		ll t = ask1(1, l, i);
		vt.pb({t, i});
	}
	sort(vt.begin(), vt.end());
	v1.pb(vt[0].second);
	for(int i=1; i<vt.size(); i++){
		int k = ask2(l, v1.back(), vt[i].second);
		if(k==-1){
			v2.pb(v1.back()); v1.pop_back();
		}
		v1.pb(vt[i].second);
	}
	while(!v2.empty()){
		v1.pb(v2.back());
		v2.pop_back();
	}
	printf("0 ");
	for(int i=0; i<v1.size(); i++){
		printf("%d ", v1[i]);
	}
	fflush(stdout);
	return 0;
}