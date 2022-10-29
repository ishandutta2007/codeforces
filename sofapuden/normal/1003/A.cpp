#include <bits/stdc++.h>

using namespace std;

int main(){
	map<int,int> m;
	int n; cin >> n;
	int ans = 0;
	for(int i = 0; i  < n; ++i){
		int tmp; cin >> tmp;
		m[tmp]++;
		ans = max(ans,m[tmp]);
	}
	cout << ans << "\n";
}