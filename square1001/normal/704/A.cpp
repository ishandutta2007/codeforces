#include <set>
#include <iostream>
using namespace std;
int n, q, tp, x, a[300009]; set<int> s[300009];
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> q;
	set<int> r;
	int id = 0;
	for (int i = 0; i < q; i++) {
		cin >> tp >> x;
		if (tp == 1) {
			s[x].insert(id);
			r.insert(id);
			a[id++] = x;
		}
		if (tp == 2) {
			for (int j : s[x]) r.erase(j);
			s[x].clear();
		}
		if (tp == 3) {
			set<int>::iterator it = r.begin();
			while(it != r.end()) {
				if (*it >= x) break;
				s[a[*it]].erase(*it);
				it++;
			}
			r.erase(r.begin(), it);
		}
		cout << r.size() << endl;
	}
	return 0;
}