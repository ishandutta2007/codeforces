#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, h;
	cin >> n >> h;
	double area = h/2.0;
	double ar = area/(n+0.0);
	double ch = h+0.0;
	cout << fixed << setprecision(10);
	vector<double> pa;
	for (int i = 0; i < n-1; i++) {
		double ans = ch*ch - 2*ar*h;
		ch = sqrt(ans);
		pa.push_back(ch);

	}
	reverse(pa.begin(), pa.end());
	for (int i = 0; i < n-1; i++) {
		cout << pa[i] << "  ";
	}
	
	cout << endl;
	cin >> n;
}