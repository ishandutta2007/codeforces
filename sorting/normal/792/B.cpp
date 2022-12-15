#include <bits/stdc++.h>

using namespace std;

const int N = 107;

int v[N], a[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;

	cin >> n >> k;

	for(int i = 0; i < k; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n; i++){
		v[i] = i + 1; 
	}

	int leader = 0;

	for(int i = 0; i < k; i++, n--){
		leader = leader + a[i];
		leader %= n;

		//cout << leader << "\n";

		cout << v[leader] << " ";

		for(int j = leader; j < n - 1; j++){
			v[j] = v[j + 1];
		}
		//leader++;
		leader %= (n - 1);
	}
	cout << "\n";

	return 0;
}