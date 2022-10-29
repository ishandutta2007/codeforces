#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x). rend()

using namespace std;
typedef long long ll;
typedef vector<int> vi;

void solve(){
	int cups = 4;
	int med = 9;
	for(int i = 0; i < 6; ++i){
		int tmp; cin >> tmp;
		if(i < 3){
			cups+=tmp;
		}
		else{
			med += tmp;
		}
	}
	int n; cin >> n;
	if(cups/5+med/10 <= n){
		cout << "YES\n";
	}
	else{
		cout << "NO\n";
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	solve();
}