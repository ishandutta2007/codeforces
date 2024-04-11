#include<bits/stdc++.h>

using namespace std;

void solve(){
	string s; cin >> s;
	int n = s.size();
	cout << abs(s[0]-s.back()) << ' ';
	vector<pair<char,int>> v(n);
	for(int i = 0; i < n; ++i){
		v[i] = {s[i],i+1};
	}
	sort(v.begin(),v.end());
	vector<int> out;
	bool ok = 0;
	for(int i = 0; i < n; ++i){
		if(v[i].second == 1 || v[i].second == n){
			ok^=1;
		}
		else if(ok)out.push_back(v[i].second);
		else if(v[i].first == s[0] || v[i].first == s.back())out.push_back(v[i].second);
	}
	if(s[0] > s.back())reverse(out.begin(),out.end());
	cout << out.size()+2 << '\n';
	cout << 1 << ' ';
	for(auto x : out)cout << x << ' ';
	cout << n << '\n';
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--)solve();

}