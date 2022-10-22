#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp(x , y) make_pair(x , y)
#define wall cerr<<"--------------------------------------"<<endl
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 2e5 + 17 , md = 1e9 + 7 , inf = 2e16;

string s , t;

void solve(){
	s.clear();
	ll n;
	cin>>n>>t;
	for(ll i = n - 1 ; ~i ;){
		if(t[i] == '0'){
			s += 'a' + (t[i - 2] - '0') * 10 + (t[i - 1] - '0') - 1;
			i -= 3;
		} else {
			s += 'a' + (t[i] - '0') - 1;
			i--;
		}
	}
	reverse(all(s));
	cout<<s<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}