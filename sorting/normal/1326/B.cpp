#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> b(n);
	for(int i = 0; i < n; ++i)
		cin >> b[i];

	int mx = 0;
	for(int i = 0; i < n; ++i){
		int curr = mx + b[i];
		cout << curr << " ";
		mx = max(mx, curr);
	}
	cout << "\n";
}