#include <bits/stdc++.h>
#define ll long long
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int MOD1 = 1e9 + 7;
const int MOD2 = 998244353;

struct Hasher{ 
	vector<int> a, h, rev;
	
    int p, mod;
    
    Hasher(const vector<int>& a, int p, int mod): a(a), p(p), mod(mod) {
        build();
    }

	int bp(int a, int k){
		if (k == 0) return 1;
		if (k % 2 == 1){
			return a * (ll)bp(a, k - 1) % mod;
		} else {
			int q = bp(a, k >> 1);
			return q * (ll)q % mod;
		}
	}

	void build(){
		rev.resize(a.size() + 1); h.resize(a.size() + 1);
		rev[0] = 1;
		h[0] = 0;
		int deg = 1;
		for (int i = 1; i <= a.size(); i++){
			h[i] = (h[i - 1] + a[i - 1] * (ll)deg) % mod;
			deg = deg * (ll)p % mod;
			rev[i] = bp(deg, mod - 2);
		}
	}

	int get(int l, int r){
		int ans = h[r + 1] - h[l];
		if (ans < 0) ans += mod;
		ans = ans * (ll)rev[l] % mod;
		return ans;
	}
};	


int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	string t;
	cin >> t;
	vector <int> a, ra;
	vector <int> pos;
	for (int i = 0; i < n; i++) {
		if (t[i] == '0') {
			a.push_back(i % 2);
			pos.push_back(i);
			ra.push_back(1 - a.back());
		}
	}
	Hasher ha1(a, 31, MOD1);
	Hasher ha2(a, 31, MOD2);

	Hasher hra1(ra, 31, MOD1);
	Hasher hra2(ra, 31, MOD2);

	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int l1, l2, len;
		cin >> l1 >> l2 >> len;
		l1--, l2--;

		int posl_1 = lower_bound(pos.begin(), pos.end(), l1) - pos.begin();
		int posr_1 = upper_bound(pos.begin(), pos.end(), l1 + len - 1) - pos.begin() - 1;
		int cnta = max(0, posr_1 - posl_1 + 1);

		int posl_2 = lower_bound(pos.begin(), pos.end(), l2) - pos.begin();
		int posr_2 = upper_bound(pos.begin(), pos.end(), l2 + len - 1) - pos.begin() - 1;
		int cntb = max(0, posr_2 - posl_2 + 1);

		if (cnta != cntb) {
			cout << "No\n";
			continue;
		}

		if (!cnta) {
			cout << "Yes\n";
			continue;
		}

		int h1 = ha1.get(posl_1, posr_1);
		int h2 = ha2.get(posl_1, posr_1);

		//cout << h1 << " " << h2 << "\n";

		int da = pos[posl_1] - l1, db = pos[posl_2] - l2;
		if (da % 2 != db % 2) {
			cout << "No\n";
			continue;
		}

		int h3, h4;

		//cout << posl_1 << " " << posr_1 << " " << posl_2 << " " << posr_2 << "\n";

		//cout << a[posl_1] << " " << ra[posl_2] << "\n";

		if (pos[posl_1] % 2 == pos[posl_2] % 2) {
			h3 = ha1.get(posl_2, posr_2);
			h4 = ha2.get(posl_2, posr_2);
		} else {
			h3 = hra1.get(posl_2, posr_2);
			h4 = hra2.get(posl_2, posr_2);
		}

		if (h3 != h1 || h4 != h2) {
			cout << "No\n";
		} else {
			cout << "Yes\n";
		}
	}
}