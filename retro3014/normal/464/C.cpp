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
const int MAX_K = 10;

string str;
int N;
vector<pair<int, vector<int> > > v;
string a;
vector<int> b;
ll len[MAX_K+1], d[MAX_K+1];

ll multi(ll x, ll y){
	if(y==0)	return 1;
	if(y==1)	return x%MOD;
	ll m = multi(x, y/2);
	if(y%2){
		return (m*m%MOD)*x%MOD;
	}
	return m*m%MOD;
}


int main(){
	cin>>str;
	cin>>N;
	for(int i=0; i<N; i++){
		int x;
		cin>>a;
		x = (a[0]-'0');
		b.clear();
		for(int i=3; i<a.size(); i++)	b.pb(a[i]-'0');
		v.pb((pair<int, vector<int> >){x, b});
	}
	for(int i=0; i<10; i++){
		len[i] = (ll)1; d[i] = (ll)i;
	}
	while(!v.empty()){
		pair<int, vector<int> > p = v.back(); v.pop_back();
		int k = p.first; vector<int> n = p.second;
		ll nl=0, nd=0; 
		for(int i : n){
			nl = (nl + len[i]) % (MOD-1);
			nd = ((nd*multi((ll)10, len[i])%MOD) + d[i]) % MOD;
		}
		len[k] = nl; d[k] = nd;
	}
	ll ans = 0;
	for(char c : str){
		int i = c-'0';
		ans = (ans * multi((ll)10, len[i])%MOD + d[i])%MOD;
	}
	cout<<ans;
	return 0;
}