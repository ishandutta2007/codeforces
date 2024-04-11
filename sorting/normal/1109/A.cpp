#include <bits/stdc++.h>

using namespace std;

const long long N = 3e5 + 7;

long long a[N];
map<long long, long long> even, odd;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n;

	cin >> n;

	for(long long i = 0; i < n; i++){
		cin >> a[i];
	}

	long long curr_xor = 0, res = 0;

	odd[0] = 1;

	for(long long i = 0; i < n; i++){
		curr_xor ^= a[i];

		if(i & 1){
			res += odd[curr_xor];
			odd[curr_xor]++;
		}
		else{
			res += even[curr_xor];
			even[curr_xor]++;
		}
	}

	cout << res << "\n";

	return 0;
}