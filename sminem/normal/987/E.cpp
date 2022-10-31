#include <bits/stdc++.h>
using namespace std;

template<class T, int size>
struct fenwick {
	T a[size];

	/* precondition: pos > 0 */
	void add(int pos, const T& val) {
		while (pos < size) {
			a[pos] += val;
			pos += pos & -pos;
		}
	}

	T sum(int pos) {
		T ret = T();
		while (pos > 0) {
			ret += a[pos];
			pos -= pos & -pos;
		}
		return ret;
	}
};

int n;
int a[1000005];
fenwick<int, 1000005> drvo;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	long long inv = 0;
	for (int i=1; i<=n; i++) {
		inv += drvo.sum(n) - drvo.sum(a[i]);
		drvo.add(a[i], 1);
	}

	cout << ((n + inv + 1) % 2 ? "Petr" : "Um_nik");
}