#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct comp {
	int a;
	int b;
};

bool compC(comp l, comp r) {
	return l.a < r.a;
}


int main() {
	int n;
	cin >> n;
	vector<comp> stuff;
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		comp cur;
		cur.a = a;
		cur.b = b;
		stuff.push_back(cur);
	}
	sort (stuff.begin(), stuff.end(), compC);
	bool inv = false;
	for (int i = 0; i < n-1; i++) {
		if (stuff[i].b > stuff[i+1].b) {
			inv = true;
		}
	}
	if (inv) {
		cout << "Happy Alex" << endl;
	}
	else cout << "Poor Alex" << endl;

	// cin >> n;
}