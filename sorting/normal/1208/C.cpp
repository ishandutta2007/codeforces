#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	cin >> n;

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cout << (i / 4) * (4 * n) + (j / 4) * 16 + (i % 4) * 4 + (j % 4) << " ";
		}
		cout << "\n";
	}

	return 0;
}