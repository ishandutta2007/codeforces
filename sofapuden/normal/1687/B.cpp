#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
	int n, m; cin >> n >> m;
	vector<pair<int,int>> we;
	for(int i = 0; i < m; ++i){
		string s(m,'0');
		s[i] = '1';
		cout << "? " << s << endl;
		int x; cin >> x;
		we.emplace_back(x,i);
	}
	sort(we.begin(),we.end());
	string s(m,'0');
	int ls = 0;
	for(int i = 0; i < m; ++i){
		s[we[i].second] = '1';
		cout << "? " << s << endl;
		int x; cin >> x;
		if(x-ls == we[i].first){
			ls = x;
		}
		else{
			s[we[i].second] = '0';
		}
	}
	cout << "! " << ls << endl;
}

int main(){
	solve();


}