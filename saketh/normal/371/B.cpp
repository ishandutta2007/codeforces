#include <bits/stdc++.h>
using namespace std;

int A, B;

tuple<int, int, int, int> solve(int value) {
	int first = 0;
	int second = 0;
	int third = 0;

	for (; value % 2 == 0; value /= 2) first++;
	for (; value % 3 == 0; value /= 3) second++;
	for (; value % 5 == 0; value /= 5) third++;

	return make_tuple(first, second, third, value);
}


int main() {
	cin >> A >> B;

	int ans = 0;

	tuple<int, int, int, int> v1 = solve(A);
	tuple<int, int, int, int> v2 = solve(B);

	if (get<3>(v1) != get<3>(v2)) { cout << -1 << endl; return 0; }

	ans += max(get<0>(v1), get<0>(v2)) - min(get<0>(v1), get<0>(v2));
	ans += max(get<1>(v1), get<1>(v2)) - min(get<1>(v1), get<1>(v2));
	ans += max(get<2>(v1), get<2>(v2)) - min(get<2>(v1), get<2>(v2));

	cout << ans << "\n";
}