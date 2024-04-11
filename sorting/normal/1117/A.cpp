#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;

int a[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	cin >> n;

	int mx = -1;

	for(int i = 0; i < n; i++){
		cin >> a[i];

		mx = max(mx, a[i]);
	}

	int res = 0, curr = 0;

	for(int i = 0; i < n; i++){
		if(a[i] == mx){
			curr++;
		}
		else{
			curr = 0;
		}
		res = max(curr, res);
	}

	cout << res << "\n";

	return 0;
}