#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;

void solve(){
	
}

int main(){
	int n; cin >> n;
	int ans = 1;
	int th = 0;
	for(int i = 0; i < n; ++i){
		int cu = 0;
		for(int j = 0, tmp; j < 4; ++j){
			cin >> tmp;
			cu+= tmp;
		}
		if( i == 0){
			th = cu;
		}
		if(cu > th){
			ans++;
		}
	}
	cout << ans << "\n";
}