#include<bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	vector<int> a(n);
	for(auto &x : a)cin >> x;
	sort(a.begin(), a.end());
	int m; cin >> m;
	vector<int> b(m);
	for(auto &x : b)cin >> x;
	sort(b.begin(), b.end());
	int l = 0, r = 0;
	int ans = 0;
	while(l < n && r < m){
		if(abs(a[l] - b[r]) <= 1){
			l++, r++, ans++;
		}
		else{
			if(a[l] > b[r]){
				r++;
			}
			else{
				l++;
			}
		}
	}
	cout << ans << "\n";
}