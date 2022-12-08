#include <bits/stdc++.h>

using namespace std;
#define maxn 100010
int n, m;

int delt[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	vector<int> vert;
	int cur;
	for (int i = 0; i  < n; i++) {
		cin >> cur;
		vert.push_back(cur);
	}
	sort(vert.begin(), vert.end());
	vert.push_back(1000000000);

	int x1, x2, y;
	int numbad = 0;
	for (int i = 0; i < m; i++) {
		cin >> x1 >> x2 >> y;
		if (x1 != 1) continue; //this guy does not matter then
		//y does not matter either
		numbad++; //there is another bad
		//find first guy greater than x2
		int indo = upper_bound(vert.begin(), vert.end(), x2) - vert.begin();
		delt[indo]--; //save 1 more
	}

	int ccost = numbad;
	int ans = n+m;
	for (int i = 0; i < vert.size(); i++) {

		//consider this as the first vetical line in it
		ccost += delt[i];
		ans = min(ans, ccost);
		ccost++;
	}

	cout << ans << endl;
}