#include <vector>
#include <iostream>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;
struct query {
	int t, id, tp;
};
bool compare(const query& q1, const query& q2) {
	if (q1.t != q2.t) return q1.t < q2.t;
	return q1.tp > q2.tp;
}
int n, q, t[100009], c[100009], d[100009], val[109], res[100009];
int main() {
	scanf("%d%d", &n, &q);
	vector<query> v;
	for (int i = 0; i < q; i++) {
		scanf("%d%d%d", &t[i], &c[i], &d[i]);
		v.push_back(query{ t[i], i, 0 });
		v.push_back(query{ t[i] + d[i], i, 1 });
	}
	sort(v.begin(), v.end(), compare);
	fill(val, val + n, -1);
	for (int i = 0; i < v.size(); i++) {
		if (v[i].tp == 1) {
			for (int j = 0; j < n; j++) {
				if (val[j] == v[i].id) val[j] = -1;
			}
		}
		else {
			int cnt = 0;
			for (int j = 0; j < n; j++) {
				if (val[j] == -1) cnt++;
			}
			if (c[v[i].id] > cnt) res[v[i].id] = -1;
			else {
				for (int j = 0, k = 0; k < c[v[i].id]; j++) {
					if (val[j] == -1) {
						val[j] = v[i].id;
						res[v[i].id] += j + 1;
						k++;
					}
				}
			}
		}
	}
	for (int i = 0; i < q; i++) printf("%d\n", res[i]);
	return 0;
}