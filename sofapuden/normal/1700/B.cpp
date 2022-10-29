#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

void solve(){
	int n; cin >> n;
	string s; cin >> s;
	if(s[0] != '9'){
		for(auto x : s)cout << '9'-x;
		cout << '\n';
	}
	else{
		string t;
		for(int i = n-1; ~i; --i){
			if(s[i] <= '1'){
				t+=(char)('1'-s[i]+'0');
			}
			else{
				if(i)s[i-1]+=1;
				t+=(char)(11-s[i]+2*'0');
			}
		}
		reverse(t.begin(),t.end());
		cout << t << '\n';
	}
}

int main(){
	int t; cin >> t;
	while(t--)solve();

}