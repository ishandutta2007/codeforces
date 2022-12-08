#include <bits/stdc++.h>

using namespace std;
#define maxn 1010

int nums[maxn];
int l[maxn];
int r[maxn];
int n;

map<int, int> mynum;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	set<int> numbig;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> l[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> r[i];
	}
	for (int i = 1; i <= n; i++) {
		// cout << i << ": " << l[i] + r[i] << endl;
		numbig.insert(l[i] + r[i]);
	}
	int ct = 0;
	vector<int> stuff;
	for (int val : numbig) {
		stuff.push_back(val);
	}
	reverse(stuff.begin(), stuff.end());
	for (int i = 0; i < stuff.size(); i++) {
		mynum[stuff[i]] = i+1;
	}
	for (int i = 1; i <= n; i++) {
		nums[i] = mynum[l[i] + r[i]];
	}

	for (int i = 1; i <= n; i++) {

		int cl = 0;
		for (int j = 1; j < i; j++) {
			if (nums[j] > nums[i]) cl++;
		}
		int cr = 0;
		for (int j = i+1; j <= n; j++) {
			if (nums[j] > nums[i]) cr++;
		}
		if (cl != l[i] || cr != r[i]) {
			cout << "NO" << endl;
			return 0;
		}

	}
	cout << "YES" << endl;
	for (int i = 1; i <= n; i++) {
		cout << nums[i] << " ";
	}
	cout << endl;
}