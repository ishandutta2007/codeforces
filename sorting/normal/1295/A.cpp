#include <bits/stdc++.h>

using namespace std;

int digits[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

void solve(){
	int n;
	cin >> n;

	if(n & 1)
		cout << "7";
	else
		cout << "1";

	for(int i = 0; i < (n - 2) / 2; ++i)
		cout << "1";
	cout << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while(t--)
		solve();
}