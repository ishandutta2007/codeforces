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
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};

const ll MAXN = 2e5 + 15 , MAXP = 2e4 , md = 1e9 + 7 , inf = 1e18;

set<ll , greater<ll> > ch;
ll cnt[26] , frc = 0 , n , k;
string s;

ll ans(ll o){
	if(o == n - 1){
		return (frc == 0 ? o : -1);
	}
	cnt[s[o] - 'a']++;
	frc--;
	if(cnt[s[o] - 'a'] % k == 1){
		frc += k;
		ch.insert(s[o] - 'a');
	}
	if(cnt[s[o] - 'a'] % k == 0){
		ch.erase(s[o] - 'a');
	}
	ll h = ans(o + 1);
	if(h != -1){
		return h;
	}
	ll q = n - o - 1;
	if(s[o + 1] == 'z'){
		cnt[s[o] - 'a']--;
		frc++;
		if(cnt[s[o] - 'a'] % k == k - 1){
			ch.insert(s[o] - 'a');
		}
		if(cnt[s[o] - 'a'] % k == 0){
			frc -= k;
			ch.erase(s[o] - 'a');
		}
		return -1;
	}
	if(frc > q){
		cnt[s[o] - 'a']--;
		frc++;
		if(cnt[s[o] - 'a'] % k == k - 1){
			ch.insert(s[o] - 'a');
		}
		if(cnt[s[o] - 'a'] % k == 0){
			frc -= k;
			ch.erase(s[o] - 'a');
		}
		return -1;
	}
	ll u = *ch.begin();
	if(frc == q && u <= s[o + 1] - 'a'){
		cnt[s[o] - 'a']--;
		frc++;
		if(cnt[s[o] - 'a'] % k == k - 1){
			ch.insert(s[o] - 'a');
		}
		if(cnt[s[o] - 'a'] % k == 0){
			frc -= k;
			ch.erase(s[o] - 'a');
		}
		return -1;
	}
	return o;
}

void solve(){
	memset(cnt , 0 , sizeof(cnt));
	ch.clear();
	frc = 0;
	string e;
	cin>>n>>k>>s;
	if(n % k){
		cout<<"-1\n";
		return;
	}
	if(k == 1){
		cout<<s<<'\n';
		return;
	}
	for(ll i = 0 ; i < n ; i++){
		cnt[s[i] - 'a']++;
	}
	bool hmm = false;
	for(ll j = 0 ; j < 26 ; j++){
		hmm |= (cnt[j] % k);
	}
	if(!hmm){
		cout<<s<<'\n';
		return;
	}
	memset(cnt , 0 , sizeof(cnt));	
	ll h = ans(0);
	if(h == -1){
		e += s[0] + 1;
		for(ll i = k ; i < n ; i++){
			e += 'a';
		}
		for(ll i = 1 ; i < k ; i++){
			e += s[0] + 1;
		}
		cout<<e<<'\n';
		return;
	}
	for(ll i = 0 ; i <= h ; i++){
		e += s[i];
	}
	ch.insert(-1);
	auto it = ch.begin();
	while(*it > s[h + 1] - 'a'){
		it++;
	}
	it--;
	ll r = *it;
	if(frc < n - h - 1){
		r = s[h + 1] - 'a' + 1;
	}
	e += r + 'a';
	cnt[r]++;
	ch.insert(r);
	string y;
	for(it = ch.begin() ; *it > -1 ; it++){
		ll u = *it;
		while(cnt[u] % k){
			cnt[u]++;
			y += u + 'a';
		}
	}
	ll lm = n - e.size() - y.size();
	for(ll i = 0 ; i < lm ; i++){
		e += 'a';
	}
	reverse(all(y));
	e += y;
	cout<<e<<'\n';
	return;
}

/*
1
6 2
azzzzz
*/

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--){
		solve();
	}	
	return 0;
}

/*

*/