#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define endl "\n"
#define INF 9223372036854775807L
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


int n, m;
ll nums[200005];

struct segtree {
	int l, r;
	segtree *lChild, *rChild;
	ll val;
	ll prop = 0;

	segtree(int l, int r) {
		this->l = l;
		this->r = r;
		if(l == r) {
			val = nums[l];
			return;
		}
		int mid = (l + r) / 2;
		lChild = new segtree(l, mid);
		rChild = new segtree(mid + 1, r);
		val = min(lChild->val, rChild->val);
	}

	void update(int lRange, int rRange, ll amt) {
		if(l > rRange || r < lRange) return;
		// cout << l << " " << r << endl;
		if(l >= lRange && r <= rRange) {
			prop += amt;
			return;
		}

		propagate();
		lChild->update(lRange, rRange, amt);
		rChild->update(lRange, rRange, amt);
		val = min(lChild->val + lChild->prop, rChild->val + rChild->prop);
	}	

	ll rmq(int lRange, int rRange) {
		if(l > rRange || r < lRange) return INF;
		// cout << l << " " << r << endl;
		propagate();
		if(l >= lRange && r <= rRange) return val;
		return min(lChild->rmq(lRange, rRange), rChild->rmq(lRange, rRange));
	}

	void propagate() {
		if(prop == 0) return;
		val += prop;
		if(l != r) {
			lChild->prop += prop;
			rChild->prop += prop;
		}
		prop = 0;
	}
};

typedef struct segtree segtree;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);

	cin >> n;

	for(int i = 0;i < n;i ++) {
		cin >> nums[i];
	}
	cin >> m;
		string line;
	getline(cin, line);
	segtree s(0, n - 1);
	for(int i = 0;i < m;i ++) {
		vector<int> nums;

		getline(cin, line);
		stringstream ss(line);
		int x;
		while(ss >> x) nums.pb(x);

		if(nums.size() == 3) {
			if(nums[2] == 0) continue;
			if(nums[0] <= nums[1]) {
				s.update(nums[0], nums[1], nums[2]);
			} else {
				s.update(nums[0], n - 1, nums[2]);
				s.update(0, nums[1], nums[2]);
			}
		} else {
			if(nums[0] <= nums[1]) {
				// cout << nums[0] << " h" << nums[1] << endl;
				cout << s.rmq(nums[0], nums[1]) << endl;
			} else {
				cout << (min(s.rmq(nums[0], n - 1), s.rmq(0, nums[1]))) << endl;
			}
		}
	}
}