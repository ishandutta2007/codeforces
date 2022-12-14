//In the name of God
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 2e3 + 9;
vector<pii> ans;
int p[N], q[N], pos[N];
int main() {
	int n; scanf("%d", &n);
	int res = 0;
	for (int i = 0; i < n; i++) scanf("%d", &p[i]);
	for (int i = 0; i < n; i++) scanf("%d", &q[i]), pos[q[i]] = i;
	for (int i = 0; i < n; i++)
		res += abs(i - pos[p[i]]);
	for (int i = 0; i < n; i++) if (p[i] != q[i]) {
		int id = 0;
		for (int j = i + 1; j < n; j++)
			if (q[i] == p[j]) {
				id = j;
				break;
			}
		while (id != i) {
			for (int j = i; j < id; j++)
				if (pos[p[j]] >= id) {
					swap(id, j);
					swap(p[id], p[j]);
			//		cout << "swapped " <<  id + 1 << ' ' << j + 1 << endl;
					ans.push_back({id + 1, j + 1});
					break;
				}
//			cout << i << ' ' << id << endl;
//			if (i == 2 && id == 0) {
//				return 0;	
//			}
		}
	}
	printf("%d\n", res / 2);
	printf("%d\n", (int) ans.size());
	for (int i = 0; i < (int) ans.size(); i++) {
		int x = ans[i].first, y = ans[i].second;
		printf("%d %d\n", x, y);	
	}
	
}