#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, 
	tree_order_statistics_node_update> ordered_set;

map<int, ordered_set> mp1, mp2;
int q;

int main() {
	cin >> q;
	while (q--) {
		int c, t, x;
		cin >> c >> t >> x;
		if (c == 1) mp1[x].insert(t);
		else if (c == 2) mp2[x].insert(t);
		else cout << mp1[x].order_of_key(t) - mp2[x].order_of_key(t) << endl;
	}
	return 0;
}