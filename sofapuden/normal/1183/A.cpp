#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x). rend()

using namespace std;
typedef long long ll;
typedef vector<int> vi;

bool isgood(int x){
	string xs = to_string(x);
	int ans = 0;
	for(char c : xs){
		ans+=c-'0';
	}
	return ans%4 == 0;
}	

void solve(){
	int n; cin >> n;
	for(int i = n; i <= 1e5; ++i){
		if(isgood(i)){
			cout << i << "\n";
			break;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	solve();
}