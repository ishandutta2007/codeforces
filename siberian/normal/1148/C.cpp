#include <bits/stdc++.h>

using namespace std;
#define int long long
int n;
vector<int> a;
vector<int> pos;
void read() {
	cin >> n;
	a.resize(n);
	for (auto &i : a)
		cin >> i;
	pos.resize(n);
	for (int i = 0; i < n; i++)
		pos[--a[i]] = i;
}
vector<pair<int, int> > ans;
void run() {
	for (int i = 0; i < n; i++) {
		if (pos[i] == i)
			continue;
		if (abs(pos[i] - i) * 2 >= n) {
			int ind1 = i, ind2 = pos[i];
			swap(a[ind1], a[ind2]);
			pos[a[ind1]] = ind1;
			pos[a[ind2]] = ind2;
			ans.push_back({ind1, ind2});
		}
		else if ((i < n / 2 && pos[i] < n / 2) || (i >= n / 2 && pos[i] >= n / 2)){
			int ind1 = i, ind2 = pos[i], ind3 = n - 1;
			if (i >= n / 2)
				ind3 = 0;
			ans.push_back({ind1, ind3});
			ans.push_back({ind2, ind3});
			ans.push_back({ind1, ind3});
			swap(a[ind1], a[ind3]);
			swap(a[ind2], a[ind3]);
			swap(a[ind1], a[ind3]);
			pos[a[ind1]] = ind1;
			pos[a[ind2]] = ind2;
			pos[a[ind3]] = ind3;
		}
		else {
			int ind1 = 0, ind2 = i, ind3 = pos[i], ind4 = n - 1;
			ans.push_back({ind2, ind4});
			ans.push_back({ind1, ind4});
			ans.push_back({ind1, ind3});
			ans.push_back({ind1, ind4});
			ans.push_back({ind2, ind4});
			swap(a[ind2], a[ind3]);
			pos[a[ind2]] = ind2;
			pos[a[ind3]] = ind3;
		}

		/*cout << "a = ";
		for (auto i : a)
			cout << i << " ";
		cout << endl;*/
	}
}

void write() {
	cout << ans.size() << endl;
	for (auto i : ans)
		cout << i.first + 1 << " " << i.second + 1 << "\n";
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	run();
	write();
	return 0;
}