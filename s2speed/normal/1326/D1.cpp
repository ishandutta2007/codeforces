#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

bool pal(string s){
	string h = s;
	reverse(h.begin() , h.end());
	if(s == h){
		return true;
	} else {
		return false;
	}
}

string cut(string s , ll l , ll r){
	string h;
	h += s.substr(0 , l);
	if(r < s.size()) h += s.substr(r , s.size() - r);
	return h;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll T , m = 0 , e = 0;
	string s , w , h , t;
	cin>>T;
	while(T > 0){
		h = "";
		w = "";
		e = 0;
		m = 0;
		cin>>s;
		for(int i = 0 ; i < s.size() / 2 ; i++){
			if(s[i] != s[s.size() - i - 1]){
				w = s.substr(0 , i);
				e = i;
				break;
			}
		}
		for(int i = e ; i < s.size() - e ; i++){
			h += s[i];
			if(pal(h) == true){
				t = h;
				m = h.size();
			}
		}
		h = "";
		for(int i = s.size() - e - 1 ; i >= e ; i--){
			h += s[i];
			if(pal(h) == true && h.size() > m){
				t = h;
				m = h.size();
			}
		}
		cout<<w + t;
		reverse(w.begin() , w.end());
		cout<<w<<endl;
		T--;
	}
	return 0;
}