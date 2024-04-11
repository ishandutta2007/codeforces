#include <bits/stdc++.h>

using namespace std;
using LL = long long;

int main()
{
	int n, q;

	cin >> n >> q;
	vector<int> top(n, -1), read(q, 0), prev(q, -1);
	int allRead = 0;
	int p = 0;
	int num = 0;
	for (int i = 0; i < q; i++) {
		int typ;
		cin >> typ;
		if (typ == 1) {
			int x;
			cin >> x;
			x--;
			prev[p] = top[x];
			top[x] = p;
			read[p] = 0;
			p++;
			num++;
			cout << num << endl;
		}
		else if (typ == 2) {
			int x;
			cin >> x;
			x--;
			int px = top[x];
			while (px != -1 && !read[px]) {
				num--;
				read[px] = 1;
				px = prev[px];
			}
			cout << num << endl;
		}
		else {
			int tr;
			cin >> tr;
			while (allRead < tr) {
				if (!read[allRead]) {
					num--;
				}
				read[allRead++] = 1;
			}
			cout << num << endl;
		}
	}
	exit(0);
}