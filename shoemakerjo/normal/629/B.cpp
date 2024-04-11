#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int mc = 0;
	int fc = 0;
	int minc[400];
	int finc[400];
	fill(minc, minc+400, 0);
	fill(finc, finc+400, 0);
	string tp;
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> tp >> a >> b;
		if (tp == "M") {
			minc[a]++;
			minc[b+1]--;
		}
		else {
			finc[a]++;
			finc[b+1]--;
		}
	}
	int ans = 0;
	for (int i = 0; i < 400; i++) {
		mc += minc[i];
		fc += finc[i];
		ans = max(ans, min(mc, fc));
	}
	cout << ans*2 << endl;
	cin >> ans;
}