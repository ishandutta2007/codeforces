#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const vector<long long> arr = {
	999917266738362368,
	999988220452765909,
	999908326373204009,
	999940111774602057,
	999965058848838029,
	999836608922529251,
	999988688533604771,
	999857663600302163,
	999989807092188397,
	999997550573275589,
	999861104955508549,
	999939187144038125,
	999811893518395379,
	998273209131921967,
	546399719195948513,
	34933
};
int numdivs(int x) {
	// returns the number of divisors of x
	int ans = 1;
	for(int i = 2; i * i <= x; ++i) {
		if(x % i == 0) {
			int b = 1;
			while(x % i == 0) {
				x /= i;
				++b;
			}
			ans *= b;
		}
	}
	if(x > 1) ans *= 2;
	return ans;
}
int main() {
	int Q;
	cin >> Q;
	while(Q--) {
		int ans = 1, x;
		for(long long i : arr) {
			cout << "? " << i << endl;
			cin >> x;
			ans *= numdivs(x);
		}
		cout << "! " << max(ans + 7, ans * 2) << endl;
	}
	return 0;
}