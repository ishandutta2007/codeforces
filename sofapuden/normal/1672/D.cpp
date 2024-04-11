#include<bits/stdc++.h>

using namespace std;

void solve(int testID){
	int n; cin >> n;
	vector<int> a(n), b(n); for(auto &x : a)cin >> x; for(auto &x : b)cin >> x;
	map<int,int> us;
	int l = n-1, r = n-1;
	while(~r){
		if(a[l] == b[r]){
			l--, r--;
			continue;
		}
		if(r != n-1 && b[r] == b[r+1]){
			us[b[r]]++;
			r--;
			continue;
		}
		if(us[a[l]]){
			us[a[l]]--;
			l--;
			continue;
		}
		break;
	}
	cout << (~r ? "NO" : "YES") << '\n';
}

int main(){
	int t; cin >> t;
	int cn = 1;
	while(t--){
		solve(cn++);

	}

}