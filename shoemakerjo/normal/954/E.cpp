#include <bits/stdc++.h>

using namespace std;
#define pii pair<int, int>

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, T;
	cin >> n >> T;
	//idk where to use doubles
	vector<pii> bef;
	vector<pii> aft;
	double bsum = 0.0;
	double asum = 0.0; 
	double ans = 0.0;
	int a, t;
	int av[n], tv[n];
	for (int i = 0; i < n; i++) {
		cin >> av[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> tv[i];
	}
	for (int i = 0; i < n; i++) {
		a = av[i];
		t = tv[i];
		if (t < T) {
			bef.push_back(pii(t, a));
			bsum += a*(T-t-0.0);
		}
		else if (t > T) {
			aft.push_back(pii(t, a));
			asum += a*(t-T-0.0);
		}
		else {
			ans += a; //don't want to deal with this
		}
	}
	// cout << "here  " << ans << endl;
	sort(bef.begin(), bef.end());
	reverse(bef.begin(), bef.end()); //want this backwards
	sort(aft.begin(), aft.end());
	// cout << "sums  " << asum << "  " << bsum << endl;
	if (asum >= bsum) {
		for (int i = 0; i < bef.size(); i++) {
			ans += bef[i].second+0.0;
		}
		for (int j = 0; j < aft.size(); j++) {
			double tk = (aft[j].first-T-0.0)*(aft[j].second); //the sum we can take
			// cout << "here   " << tk  << "  " << bsum << endl;
			if (tk > bsum) {
				ans += bsum/(aft[j].first-T-0.0);
				break;
			}
			bsum -= tk;
			ans += aft[j].second;

		}
	}
	else {
		for (int i = 0; i < aft.size(); i++) {
			ans += aft[i].second+0.0;
		}
		for (int j = 0; j < bef.size(); j++) {
			double tk = (T-bef[j].first-0.0)*(bef[j].second); //the sum we can take
			if (tk > asum) {
				ans += asum/(T-bef[j].first-0.0);
				break;
			}
			asum -= tk;
			ans += bef[j].second;

		}
	}
	cout << fixed << setprecision(15);
	cout << ans << endl;
	cin >> n;
}