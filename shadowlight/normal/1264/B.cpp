#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int w[4], sw[4];

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		cin >> w[i];
		sum += w[i];
	}
	for (int i = 0; i < 4; i++) {
		sw[i] = w[i];
	}
	vector <int> res;
	for (int st = 0; st < 4; st++) {
		int now = st;
		for (int i = 0; i < 4; i++) {
			w[i] = sw[i];
		}
		res.clear();
		while (res.size() < sum) {
			if (now == 4 || !w[now]) {
				break;
			}
			w[now]--;
			res.push_back(now);
			if (now && w[now - 1]) {
				now--;
			} else {
				now++;
			}
		} 
		//cout << st << " " << res.size() << "\n";
		if (res.size() == sum) {
			cout << "YES\n";
			for (int x : res) {
				cout << x << " ";
			}
			return 0;
		}
	}
	cout << "NO\n";
}