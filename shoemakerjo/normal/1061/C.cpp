#include <bits/stdc++.h>

using namespace std;
#define pii pair<int, int>
#define ll long long 

const int maxn = 100010;
const int mod = 1000000007;
int n;

ll curlen[maxn*10];
int nums[maxn];

void add(ll & a, ll b) {
	a = (a + b)%mod;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	curlen[0] = 1LL;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
	}
	ll ans = 0LL;

	vector<pii> additions;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j*1LL*j <= nums[i]; j++) {
			if (nums[i]%j != 0) continue;
			add(ans, curlen[j-1]);

			// cout << j << " : " << nums[i]/j << endl;

			// cout << "adding: " << j << " : " << curlen[j-1] << endl;

			if (j*j != nums[i]) {
				// cout << "adding: " << nums[i]/j << " : " << curlen[nums[i]/j-1] << endl;
// 
				add(ans, curlen[nums[i]/j - 1]);
			}

			additions.push_back(pii(j, curlen[j-1]));

			if (j * j != nums[i]) {
				additions.push_back(pii( nums[i]/j,
					curlen[nums[i]/j - 1]));
			}
		}



		for (pii val : additions) {
			// cout << "trying addition - " << val.first << " "  << val.second << endl;
			add(curlen[val.first], val.second);
		}
		additions.clear();

		// cout << "aft: " << nums[i] << " : " << ans << endl << endl;
	}
	// cout << "thing: " << curlen[1] << endl;
	cout << ans << endl;
}