#include <bits/stdc++.h>

using namespace std;

int main() {
	int m;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(0);
	cin >> m;
	int nums[m+1];

	for (int i = 1; i <= m; i++) {
		cin >> nums[i];
	}
	int q;
	cin >> q;
	vector<tuple<int, int, int, int>> qus;
	int l, r;
	for (int i = 0; i < q; i++) {
		cin >> l >> r;
		qus.push_back(make_tuple(l/sqrt(m), r, l, i));
	}
	sort(qus.begin(), qus.end());
	int prev[m+1];
	for (int i = 0; i <= m; i++) {
		prev[i] = -1;
	}
	vector<vector<int>> vd;
	vector<deque<int>> curd;
	int tho = 100000;
	int quant[tho+1];
	for (int i = 0; i <= tho; i++) {
		deque<int> b;
		vector<int> b2;
		curd.push_back(b);
		vd.push_back(b2);
	}
	for (int i = 1; i <= m; i++) {
		vd[nums[i]].push_back(i);
	}
	for (int i = 0; i <= tho; i++) {
		quant[i] = 0;
		for (int j = 0; j < vd[i].size(); j++) {
			if (j == 0) {
				prev[vd[i][j]] = 0;
			}
			else if (j == 1) {
				prev[vd[i][j]] = vd[i][j-1];
			}
			else {
				if (vd[i][j] - vd[i][j-1] == vd[i][j-1]-vd[i][j-2]) {
					prev[vd[i][j]] = prev[vd[i][j-1]];
				}
				else prev[vd[i][j]] = vd[i][j-1];
			}
		}
	}
	bool ok[tho+1];
	int okct = 0;
	for (int i = 0; i <= tho; i++) {
		ok[i] = false;
	}
	int active = 0;
	int la, ra;
	int anses[q];
	for (int i = 0; i < q; i++) {
		// cout << i << " " << q << endl;
		l = get<2>(qus[i]);
		r = get<1>(qus[i]);
		int index = get<3>(qus[i]);
		// cout << l << " " << r << endl;
		if (i == 0) {
			for (int j = l; j <= r; j++) {
				curd[nums[j]].push_back(j);
				quant[nums[j]]++;
				if (curd[nums[j]].size() == 1) {
					ok[nums[j]] = true;
					okct++;
					active++;
				}
				else if (ok[nums[j]]) {
					if (curd[nums[j]].front() < prev[j]) {
						ok[nums[j]] = false;
						okct--;
					}
				}
			}
			la = l;
			ra = r;
			int ans = active+1;
			if (okct > 0) {
				ans--;
			}
			anses[index] = ans;
			continue;
		}
		// cout << "here" << endl;
		while (ra < r) {
			ra++;
			curd[nums[ra]].push_back(ra);
			if (curd[nums[ra]].size() > 0 &&
				curd[nums[ra]].front() >= prev[curd[nums[ra]].back()]) {
				if (!ok[nums[ra]]) {
					ok[nums[ra]] = true;
					okct++;
				}
			}
			else {
				if (ok[nums[ra]]) {
					ok[nums[ra]] = false;
					okct--;
				}
			}
			quant[nums[ra]]++;
			if (quant[nums[ra]] == 1) active++;
			
		}
		while (la > l) {
			la--;
			curd[nums[la]].push_front(la);
			if (curd[nums[la]].size() > 0 &&
				curd[nums[la]].front() >= prev[curd[nums[la]].back()]) {
				if (!ok[nums[la]]) {
					ok[nums[la]] = true;
					okct++;
				}
			}
			else {
				if (ok[nums[la]]) {
					ok[nums[la]] = false;
					okct--;
				}
			}
			quant[nums[la]]++;
			if (quant[nums[la]] == 1) active++;
			
		}
		
		while (la < l) {
			// cout << "la:    " << la << endl;
			curd[nums[la]].pop_front();
			if (curd[nums[la]].size() > 0 &&
				curd[nums[la]].front() >= prev[curd[nums[la]].back()]) {
				if (!ok[nums[la]]) {
					ok[nums[la]] = true;
					okct++;
				}
			}
			else {
				if (ok[nums[la]]) {
					ok[nums[la]] = false;
					okct--;
				}
			}
			quant[nums[la]]--;
			if (quant[nums[la]] == 0) active--;
			la++;
		}
		// cout << "here" << endl;
		while (ra > r) {
			curd[nums[ra]].pop_back();
			if (curd[nums[ra]].size() > 0 &&
				curd[nums[ra]].front() >= prev[curd[nums[ra]].back()]) {
				if (!ok[nums[ra]]) {
					ok[nums[ra]] = true;
					okct++;
				}
			}
			else {
				if (ok[nums[ra]]) {
					ok[nums[ra]] = false;
					okct--;
				}
			}
			quant[nums[ra]]--;
			if (quant[nums[ra]] == 0) active--;
			ra--;
		}

		
		
		int ans = active+1;
		if (okct > 0) ans--;
		anses[index] = ans;
	}
	for (int i = 0; i < q; i++) {
		cout << anses[i] << "\n";
	}
	cin >> r;
}