#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x). rend()

using namespace std;
typedef long long ll;
typedef vector<int> vi;

void solve(){
	int x, y; cin >> x >> y;
	int hi = max(x,y);
	if(hi == 1){
		cout << "1/1\n";
	}
	else if(hi == 2){
		cout << "5/6\n";
	}
	else if(hi == 3){
		cout << "2/3\n";
	}
	else if(hi == 4){
		cout << "1/2\n";
	}
	else if(hi == 5){
		cout << "1/3\n";
	}
	else if(hi == 6){
		cout << "1/6\n";
	}
	else{
		cout << "1/0\n";
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	solve();
}