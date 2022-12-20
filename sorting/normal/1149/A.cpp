#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 7;

int cnt[3];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	cin >> n;

	for(int i = 0; i < n; i++){
		int x;

		cin >> x;

		cnt[x]++;
	}

	if(!cnt[2]){
		for(int i = 0; i < n; i++){
			cout << "1 ";
		}
		cout << "\n";
		return 0;
	}
	if(!cnt[1]){
		for(int i = 0; i < n; i++){
			cout << "2 ";
		}
		cout << "\n";
		return 0;
	}

	cout << "2 1 ";

	cnt[1]--;
	cnt[2]--;

	for(int i = 0; i < cnt[2]; i++){
		cout << "2 ";
	}
	for(int i = 0; i < cnt[1]; i++){
		cout << "1 ";
	}

	cout << "\n";

	return 0;
}