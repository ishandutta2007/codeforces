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
vector<pll> vt;
pll c;

ll ans;

bool ccw(pll a, pll b){
	return (a.first*b.second - b.first*a.second)>0;
}

bool sf(pll a, pll b){
	if((a>(pll){0LL, 0LL}) ^ (b>(pll){0LL, 0LL})){
		return a>b;
	}
	return ccw(a, b);
}

vector<pll> v;

void calc(){
	while(!v.empty())	v.pop_back();
	for(int i=0; i<vt.size(); i++){
		v.pb({vt[i].first-c.first, vt[i].second-c.second});
	}
	ll add = (ll)v.size();
	add = (add) * (add-1LL) * (add-2LL) * (add-3LL) / 24LL;
	ans+=add;
	sort(v.begin(), v.end(), sf);
	int M = v.size();
	//cout<<endl<<c.first<<" "<<c.second<<endl;
	for(int i=0; i<M; i++){
		//cout<<v[i].first<<" "<<v[i].second<<endl;
		v.pb(v[i]);
	}
	int j=0;
	for(int i=0; i<M; i++){
		j = max(i, j);
		while(j<v.size()-1 && j<i+M-1 && ccw(v[i], v[j+1])){
			j++;
		}
		//cout<<v[i].first<<" "<<v[i].second<<endl;
		//cout<<v[j].first<<" "<<v[j].second<<endl;
		add = (j-i);
		//cout<<add<<endl;
		ans -= add * (add-1LL) * (add-2LL) / 6LL;
	}

}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		ll a, b; scanf("%lld%lld", &a, &b);
		vt.pb({a, b});
	}
	c = vt.back(); vt.pop_back();
	calc();
	for(int i=0 ;i<vt.size(); i++){
		pll tmp = c; c = vt[i]; vt[i] = tmp;
		calc();
	}
	cout<<ans;
	return 0;
}