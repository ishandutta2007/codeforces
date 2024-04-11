#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

string i2s(ll a){
	string h;
	if(a == 0){
		return "0";
	}
	if(a < 0){
		h += "-";
		a = 0 - a;
	}
	while(a > 0){
		h += a % 10 + 48;
		a /= 10;
	}
	reverse(h.begin() , h.end());
	return h;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll t;
	cin>>t;
	while(t--){
		set<string> ch;
		string s , h;
		ll x = 0 , ans = 5 , y = 0;
		cin>>s;
		if(s[0] == 'N'){
			x++;
		} else if(s[0] == 'S'){
			x--;
		} else if(s[0] == 'E'){
			x += 1e6;
		} else {
			x -= 1e6;
		}
		ch.insert("0 " + i2s(x));
		ch.insert(i2s(x) + " 0");
		for(int i = 1 ; i < s.size() ; i++){
			y = x;
			if(s[i] == 'N'){
				x++;
			} else if(s[i] == 'S'){
				x--;
			} else if(s[i] == 'E'){
				x += 1e6;
			} else {
				x -= 1e6;
			}
			h = i2s(y) + " " + i2s(x);
			if(ch.find(h) == ch.end()){
				ans += 5;
				ch.insert(i2s(x) + " " + i2s(y));
				ch.insert(h);
			} else {
				ans++;
			}
		}
		cout<<ans<<endl;
		ch.clear();
	}
	return 0;
}