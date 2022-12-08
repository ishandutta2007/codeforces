#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int mod = 998244353;

const int maxn = 200010;
int n, k;

int nums[maxn];

ll mult(ll a, ll b) {
	return (a%mod)*(b%mod)%mod;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;

	//can do odds and evens differently

	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
	}
	//look at consecutive streaks of -1's?
	//if bounded by 0 1's
	// ----> just do it real easily
	//if bounded by 1 1
	//consider starting at that end --> easy
	// if bounded by 2 1's
	// ---> there is some casework here
	// ---> just calculate as if 1 end and subtract?
	// --->  store count that are equal as the right end

	ll oddans = 1;
	ll evenans = 1;
	//will multiply these later


	for (int i = 1; i <= n; i += 2) {

		int st = i, en = i;
		if (nums[i] != -1) continue;


		int sz = 1;
		while (i+2 <= n && nums[i+2] == -1) {
			i+=2;
			sz++;
		}

		en = i;

		bool bef = (st - 2) >= 1;
		bool aft = (en + 2) <= n;


		if (bef && aft) {

			ll numok = 0LL;
			ll numbad = 0LL;
			if (nums[st-2] == nums[en+2]) {
				numbad+=1LL;
			}
			else numok += 1LL;

			for (int j = 0; j < sz; j++) {

				ll nbad = numok;
				ll ngood = mult(numbad , (k-1)) + 
					mult(numok,(k-2));

				numok = ngood % mod;
				numbad = nbad;

			}

			// numok = (numok + mod - numbad)%mod;

			oddans = mult(oddans, numok);

		}
		else if (bef || aft) {
			for (int j = 0; j < sz; j++) {
				oddans = mult(oddans, k-1);
			}
		}
		else {
			oddans = mult(oddans, k);
			for (int j = 0; j < sz-1; j++) {
				oddans = mult(oddans, k-1);
			}
		}

	}
	for (int i = 2; i <= n; i += 2) {
		int st = i, en = i;
		if (nums[i] != -1) continue;


		int sz = 1;
		while (i+2 <= n && nums[i+2] == -1) {
			i+=2;
			sz++;
		}

		en = i;


		// cout << st << " to " << en << ": " << sz << endl;

		bool bef = (st - 2) >= 1;
		bool aft = (en + 2) <= n;


		if (bef && aft) {

			ll numok = 0LL;
			ll numbad = 0LL;
			if (nums[st-2] == nums[en+2]) {
				numbad+=1LL;
			}
			else numok += 1LL;

			for (int j = 0; j < sz; j++) {

				ll nbad = numok;
				ll ngood = mult(numbad , (k-1)) + 
					mult(numok,(k-2));

				numok = ngood % mod;
				numbad = nbad;

			}

			// numok = (numok + mod - numbad)%mod;

			evenans = mult(evenans, numok);

		}
		else if (bef || aft) {
			for (int j = 0; j < sz; j++) {
				evenans = mult(evenans, k-1);
			}
		}
		else {
			// cout << "here here " << endl;
			evenans = mult(evenans, k);
			for (int j = 0; j < sz-1; j++) {
				evenans = mult(evenans, k-1);
			}
		}
	}

	// cout << "odd: " << oddans << endl;
	// cout << "even: " << evenans << endl;

	// cout << mult(k, k-1) << endl;


	ll res = mult(oddans, evenans);

	for (int i = 2; i <= n; i++) {
		if (nums[i] != -1 && nums[i] == nums[i-2]) res = 0LL;
	}

	cout  << res << endl;

}