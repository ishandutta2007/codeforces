#include <bits/stdc++.h>
using namespace std;

void mxe(int &a, int b) {
	if (b > a) a = b;
}

int main() {
	int n;
	cin >> n;
	vector<vector<int>> div(n + 1);
	vector<vector<int>> num(n + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j += i) {
			div[j].push_back(i);
			num[i].push_back(j);
		}
	}

	vector<int> max_div(n + 1, -1);
	vector<bool> u(n + 1);

	vector<int> ans = {-1};
	int cur_num = 0;

	for (int d = 1; d <= n; d++) {
		//cout << d << endl;
		for (int x : num[d]) {
			if (u[x] || max_div[x] > d) continue;
			u[x] = true;
			cur_num++;

			//cout << d << " " << x << endl;

			for (int i = (int)div[x].size() - 1; div[x][i] > d; i--) {
				int dd = div[x][i];				
				//cout << "checking " << dd << endl;
				for (int xx : num[dd]) {
					//cout << "max_div " << xx << " = " << max_div[xx] << " " << dd << endl; 
					mxe(max_div[xx], dd);
				}
			}
		}

		while ((int)ans.size() <= cur_num) ans.push_back(d);
	}

	//cout << "ans" << endl;
	for (int i = 2; i <= n; i++) {
		cout << ans[i] << " ";
	}
	// cout << "ok" << endl;
}