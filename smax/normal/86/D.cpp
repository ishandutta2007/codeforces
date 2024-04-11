#include <bits/stdc++.h>
using namespace std;

#define LEN 448

inline int64_t hilbertOrder(int x, int y, int pow, int rotate) {
	if (pow == 0) {
		return 0;
	}
	int hpow = 1 << (pow-1);
	int seg = (x < hpow) ? (
		(y < hpow) ? 0 : 3
	) : (
		(y < hpow) ? 1 : 2
	);
	seg = (seg + rotate) & 3;
	const int rotateDelta[4] = {3, 0, 0, 1};
	int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
	int nrot = (rotate + rotateDelta[seg]) & 3;
	int64_t subSquareSize = int64_t(1) << (2*pow - 2);
	int64_t ans = seg * subSquareSize;
	int64_t add = hilbertOrder(nx, ny, pow-1, nrot);
	ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
	return ans;
}

bool cmp(const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b) {
    return hilbertOrder(a.first.first, a.first.second, 21, 0) < hilbertOrder(b.first.first, b.first.second, 21, 0);
}

int a[200000], k[1000001] = {};
long long sum = 0, ret[200000];
pair<pair<int, int>, int> queries[200000];

void add(int i) {
    sum -= (long long) k[a[i]] * k[a[i]] * a[i];
    k[a[i]]++;
    sum += (long long) k[a[i]] * k[a[i]] * a[i];
}

void rem(int i) {
    sum -= (long long) k[a[i]] * k[a[i]] * a[i];
    k[a[i]]--;
    sum += (long long) k[a[i]] * k[a[i]] * a[i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, t;
    cin >> n >> t;
    for (int i=0; i<n; i++)
        cin >> a[i];
    for (int i=0; i<t; i++) {
        cin >> queries[i].first.first >> queries[i].first.second;
        queries[i].second = i;
    }

    sort(queries, queries + t, cmp);

    int moLeft = 0, moRight = -1;
    for (int i=0; i<t; i++) {
        int l = queries[i].first.first - 1, r = queries[i].first.second - 1;
        while (moLeft < l)
            rem(moLeft++);
        while (moLeft > l)
            add(--moLeft);
        while (moRight < r)
            add(++moRight);
        while (moRight > r)
            rem(moRight--);
        ret[queries[i].second] = sum;
    }

    for (int i=0; i<t; i++)
        cout << ret[i] << "\n";

    return 0;
}