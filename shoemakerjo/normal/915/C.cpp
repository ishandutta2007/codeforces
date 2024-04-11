/**
* Sources: various
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()


const int MOD = 1000000007;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	ll a, b;
	cin >> a >> b;
	string bstr = to_string(b);
	string astr = to_string(a);

	int dig[10];
	for (int i = 0; i < 10; i++) dig[i] = 0;
	ll cur = a;
	vector<int> nums;

	while (cur > 0) {
		dig[cur%10]++;
		// if (cur%10 != 0) {
			nums.push_back(cur%10);
		// }
		cur /= 10;
	}
	sort(nums.begin(), nums.end());
	if (astr.length() < bstr.length()) {
		ll ans = 0LL;
		for (int i = nums.size()-1; i  >= 0; i--) {
			ans = ans*10LL + nums[i];
		}
		cout << ans << endl;
		cin >> ans;
		return 0;
	}
	
	ll ans = 0LL;
	ll base_ans = 0LL;
	for (int k = 0; k < bstr.length(); k++) {
		
		for (int i = 0; i < bstr[k]-'0'; i++) {
			if (dig[i] == 0) continue;
			ll cans = base_ans*10LL + i;
			bool proc = false;
			for (int j = nums.size()-1; j >= 0; j--) {
				if (nums[j] == i && !proc) {
					proc = true;
					continue;
				}
				cans = cans*10LL + nums[j];

			}
			ans = max(ans, cans);
		}
		if (dig[bstr[k]-'0'] > 0) {
			dig[bstr[k]-'0']--;
			base_ans = base_ans*10LL + bstr[k]-'0';
			ans = max(ans, base_ans);
		}
		else break;
		nums.clear();
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < dig[i]; j++) {
				nums.push_back(i);
			}
		}
		sort(nums.begin(), nums.end());
	}
	cout << ans << endl;
	cin >> ans;

}