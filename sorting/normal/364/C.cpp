#include <bits/stdc++.h>

using namespace std;

vector<int> res{1}, primes{2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n;

	cin >> n;

	for(auto p: primes){
		if(res.size() >= n){
			break;
		}
		for(int i = 0; i < res.size(); i++){
			if(res[i] * p <= 2 * n * n){
				res.push_back(res[i]*p);
			}
		}
	}

	for(int i = res.size() - 1; i >= res.size() - n; i--){
		cout << res[i] << " ";
	}
	cout << "\n";

	return 0;
}