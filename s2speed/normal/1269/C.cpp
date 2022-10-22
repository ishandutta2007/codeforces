#include<bits/stdc++.h>
typedef long long ll;

using namespace std;

string js1(string s){
	if(s[s.size() - 1] != '9'){
		s[s.size() - 1] = s[s.size() - 1] + 1;
		return s;
	} else {
		s[s.size() - 1] = '0';
		return js1(s.substr(0 , s.size() - 1)) + s[s.size() - 1];
	}
}

int main(){
	ll n , k;
	string s , ans , h;
	cin>>n>>k>>s;
	cout<<n<<endl;
	h = s.substr(0 , k);
	for(int i = 0 ; i < n ; i++){
		ans += h[i % k];
	}
	if(ans >= s){
		cout<<ans<<endl;
		return 0;
	}
	ans.clear();
	h = js1(h);
	for(int i = 0 ; i < n ; i++){
		ans += h[i % k];
	}
	cout<<ans<<endl;
	return 0;
}