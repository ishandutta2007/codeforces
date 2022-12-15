#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while(t--){
		int n, k;
		cin >> n >> k;

		if((n + k) & 1){
			cout << "NO\n";
			continue;
		}

		int sum = 0;
		for(int i = 0; i < k; ++i){
			sum += 2 *i + 1;
			if(sum > n)
				break;
		}

		if(sum > n)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
}