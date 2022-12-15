#include <bits/stdc++.h>

using namespace std;

const int kN = 203;

pair<int, int> pos[kN], target[kN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	for(int i = 0; i < k; ++i)
		cin >> pos[i].first >> pos[i].second;
	for(int i = 0; i < k; ++i)
		cin >> target[i].first >> target[i].second;

	string operations = "";
	for(int i = 0; i < n - 1; ++i)
		operations += "U";
	for(int i = 0; i < m - 1; ++i)
		operations += "L";

	for(int i = 0; i < n; ++i){
		if(i % 2 == 0){
			for(int i = 0; i < m - 1; ++i)
				operations += "R";
			operations += "D";
		}
		else{
			for(int i = 0; i < m - 1; ++i)
				operations += "L";
			operations += "D";
		}
	}

	cout << operations.size() << "\n";
	cout << operations << "\n";
}