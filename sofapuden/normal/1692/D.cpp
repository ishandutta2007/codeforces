#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
void solve(){
	string s; int x; cin >> s >> x;
	set<string> pal;
	for(int i = 0; i < 1440; ++i){
		int fi = stoi(s.substr(0,2));
		int si = stoi(s.substr(3,2));
		si+=x%60;
		fi+=x/60;
		fi+=si/60;
		si%=60;
		fi%=24;
		s[0] = '0'+fi/10;
		s[1] = '0'+fi%10;
		s[3] = '0'+si/10;
		s[4] = '0'+si%10;
		if(s[0] == s[4] && s[1] == s[3]){
			pal.insert(s);
		}
	}
	cout << pal.size() << '\n';
}
 
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t; while(t--)solve();
}