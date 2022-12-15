#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 7;

long long a[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n;

	cin >> n;

	if(n % 2 == 0){
		cout << "NO\n";

		return 0;
	}

	cout << "YES\n";

	for(int i = 1; i <= n; i++){
		if(i & 1){
			cout << i * 2 - 1 << " ";
		}
		else{
			cout << i * 2 << " ";
		}
	}

	for(int i = 1; i <= n; i++){
		if(i & 1){
			cout << i * 2 << " ";
		}
		else{
			cout << i * 2 - 1 << " ";
		}
	}
	cout << "\n";

	return 0;
}