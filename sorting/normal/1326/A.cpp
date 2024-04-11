#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;

		if(n == 1){
			cout << "-1\n";
			continue;
		}

		if((n - 1) % 3 == 0){
			cout << "4";
			for(int i = 0; i < n - 2; ++i)
				cout << "2";
			cout << "3\n";
		}
		else{
			for(int i = 0; i < n - 1; ++i)
				cout << "2";
			cout << "3\n";
		}
	}
}