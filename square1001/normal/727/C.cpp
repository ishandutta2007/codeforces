#include <vector>
#include <iostream>
using namespace std;
int ask(int pa, int pb) {
	cout << "? " << pa + 1 << ' ' << pb + 1 << endl;
	int res;
	cin >> res;
	return res;
}
void answer(vector<int> v) {
	cout << "!";
	for(int i : v) cout << ' ' << i;
	cout << endl;
}
int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	int x = ask(0, 1);
	int y = ask(1, 2);
	int z = ask(2, 0);
	int all = (x + y + z) / 2;
	v[0] = all - y;
	v[1] = all - z;
	v[2] = all - x;
	for(int i = 3; i < n; ++i) {
		int res = ask(0, i);
		v[i] = res - v[0];
	}
	answer(v);
	return 0;
}