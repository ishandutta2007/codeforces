#include <bits/stdc++.h>

using namespace std;

const int K = 1e5 + 7;

long long a[K];

long long A, B;

long long solve(long long l, long long r, long long l2, long long r2){
	if(l > r){
		return A;
	}
	if(l2 == r2){
		return (r - l +1) * B;
	}

	long long mid = (l2 + r2) / 2;

	if(mid < a[l]){
		long long l_res = solve(l, l - 1, l2, mid);
		long long r_res = solve(l, r, mid + 1, r2);

		long long res = (r2 - l2 + 1) * (r - l + 1) * B;

		res = min(res, l_res + r_res);

		return res;
	}

	if(mid >= a[r]){
		//cout << "right\n";

		long long l_res = solve(l, r, l2, mid);
		long long r_res = solve(r, r - 1, mid + 1, r2);

		long long res = (r2 - l2 + 1) * (r - l + 1) * B;

		res = min(res, l_res + r_res);

		return res;
	}

	for(int i = l; i < r; i++){
		if(mid >= a[i] && mid < a[i + 1]){
			long long l_res = solve(l, i, l2, mid);
			long long r_res = solve(i + 1, r, mid + 1, r2);

			long long res = (r2 - l2 + 1) * (r - l + 1) * B;

			res = min(res, l_res + r_res);

			return res;
		}
	}

	return 0;
}

int main (){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n, k;

	cin >> n >> k >> A >> B;

	for(int i = 0; i < k; i++){
		cin >> a[i];
	}

	sort(a, a + k);

	cout << solve(0, k - 1, 1, (1ll << n)) << "\n";

	return 0;
}