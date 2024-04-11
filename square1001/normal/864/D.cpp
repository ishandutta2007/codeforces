#include <vector>
#include <iostream>
using namespace std;
int n, a[200009], c[200009], f[200009], used[200009];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i], c[a[i]]++;
	vector<int> v;
	for (int i = 1; i <= n; i++) {
		if (c[i] == 0) v.push_back(i);
	}
	for (int i = 0; i < n; i++) {
		if (c[a[i]] >= 2) f[i] = true;
	}
	cout << v.size() << endl;
	int cur = 0;
	for (int i = 0; i < n; i++) {
		if (used[a[i]] || (c[a[i]] > 1 && a[i] > v[cur])) c[a[i]]--, cout << v[cur++] << ' ';
		else used[a[i]] = true, cout << a[i] << ' ';
	}
	return 0;
}