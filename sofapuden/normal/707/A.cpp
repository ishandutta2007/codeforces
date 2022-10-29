#include <bits/stdc++.h>
#define all(x) (x).begin, (x).end
#define rall(x) (x).rbegin, (x). rend

using namespace std;
typedef long long ll;
typedef vector<int> vi;

void solve(){
	int n, m; cin >> n >> m;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			char tmp;
			cin >> tmp;
			if(tmp == 'C' || tmp == 'M' || tmp == 'Y'){
				cout << "#Color\n";
				return;
			}
		}
	}
	cout << "#Black&White\n";
			
	
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	solve();
}