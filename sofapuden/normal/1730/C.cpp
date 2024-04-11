#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
	string s; cin >> s;
	string s2;
	string s3;
	int n = s.size();
	for(int i = 0; i < n; ++i){
		while(s2.size() && s2.back() > s[i]){s3+=min('9',(char)(s2.back()+1)); s2.pop_back();}
		s2+=s[i];
	}
	sort(s3.begin(),s3.end());
	int l = 0, r = 0;
	while(l < s2.size() || r < s3.size()){
		if(l == s2.size())cout << s3[r++];
		else if(r == s3.size())cout << s2[l++];
		else if(s2[l] < s3[r])cout << s2[l++];
		else cout << s3[r++];
	}
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--)solve();
}