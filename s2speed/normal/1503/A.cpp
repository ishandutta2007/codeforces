#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<ll , pll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 2e5 + 16 , md = 1e9 + 7 , inf = 2e18;

string s , a , b;

void solve(){ a.clear(); b.clear();
	ll n , cnt[] = {0 , 0} , z = 0 , x = 0;
	cin>>n>>s;
	for(ll i = 0 ; i < n ; i++){
		z += (s[i] == '0');
	}
	if(z % 1){
		cout<<"NO\n";
		return;
	}
	x = (n - z) / 2;
	for(ll i = 0 ; i < n ; i++){
		if(s[i] == '1'){
			if(x){
				a += '(';
				b += '(';
				x--;
				cnt[0]++; cnt[1]++;
			} else {
				if(min(cnt[0] , cnt[1]) == 0){
					cout<<"NO\n";
					return;
				}
				a += ')';
				b += ')';
				cnt[0]--; cnt[1]--;
			}
		} else {
			if(cnt[0] > cnt[1]){
				if(cnt[0] == 0){
					cout<<"NO\n";
					return;
				}
				a += ')';
				b += '(';
				cnt[0]--; cnt[1]++;
			} else {
				if(cnt[1] == 0){
					cout<<"NO\n";
					return;
				}
				a += '(';
				b += ')';
				cnt[0]++; cnt[1]--;
			}
		}
	}
	if(cnt[0] != 0 || cnt[1] != 0){
		cout<<"NO\n";
		return;
	}
	cout<<"YES\n"<<a<<'\n'<<b<<'\n';
	return;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}