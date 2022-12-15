#include <bits/stdc++.h>

using namespace std;

const long long N = 1e6 + 7;
const long long mx = 1e7 + 7;

long long a[N];
vector<long long> v[mx];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n;

	cin >> n;

	for(long long i = 1; i <= n; i++){
		cin >> a[i];
		v[a[i]].push_back(i);
	}

	long long res = mx * mx, idx1, idx2;

	for(long long i = 1; i < mx; i++){
		pair<long long, long long> sol = {0, 0};

		for(long long j = i; j < mx; j += i){
			for(auto x: v[j]){
				if(!sol.first){
					sol.first = x;
				}
				else{
					sol.second = x;
					break;
				}
			}
			if(sol.second){
				long long curr = a[ sol.first ]  * a[ sol.second ] / i;

				if(curr < res){
					res = curr;
					idx1 = sol.first;
					idx2 = sol.second;
				}
				break;
			}
		}
	}

	cout << min(idx1, idx2) << " " << max(idx1, idx2) << "\n";

	return 0;
}