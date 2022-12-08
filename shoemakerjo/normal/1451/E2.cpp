#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define pii pair<int, int>

const int maxn = 1 << 18;
map<int, int> mp;

int n;

int xors[maxn];

pii find_pair() {

	map<int, int> cur;
	for (int i  = 1; i <= n; i++) {
		if (cur.count(xors[i])) {
			return pii(cur[xors[i]], i);
		}
		cur[xors[i]] = i;
	}
	return {-1, -1};
}

int main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	cin >> n;

	for (int i = 2; i <= n; i++) {
		cout << "XOR " << 1 << " " << i << endl;
		cin >> xors[i];
		mp[xors[i]] = i;
	}

	//now check if there are duplicates
	pii tmp = find_pair();
	//do have a pair
	if (tmp.first != -1) {
		cout << "AND " << tmp.first << " " << tmp.second << endl;
		int res;
		cin >> res;
		int v0 = xors[tmp.first] ^ res;
		cout << "!";
		for (int i = 1; i <= n; i++) {
			cout << " " << (xors[i] ^ v0);
		}
		cout << endl;
		return 0;
	}
	//no pairs
	int myopp = mp[n-1]; //all bits are opposite me
	int to_1 = mp[1];

	int all_but_last;
	cout << "AND " << 1 << " " << to_1 << endl;
	cin >> all_but_last;

	int cval;
	cout << "AND " << myopp << " " << to_1 << endl;
	cin >> cval;

	if (cval % 2 == 0) {
		all_but_last++;
	}
	int v0 = all_but_last;
	cout << "!";
	for (int i = 1; i <= n; i++) {
		cout << " " << (xors[i] ^ v0);
	}
	cout << endl;


}