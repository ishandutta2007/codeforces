#include <bits/stdc++.h>
using namespace std;

int n;
double k;
vector<double> a;

bool check(double b) {
	double tot = 0;
	for(auto x : a) {
		if(x > b)
			tot += b + (x - b)*k;
		else
			tot += x;
	}
	return tot >= b * (double)n;
}

int main() {
	cin >> n >> k;
	k = 1.0 - k/100.0;
	for(int i = 0; i < n; i++) {
		double x;
		cin >> x;
		a.push_back(x);
	}
	double lo = 0, hi = 1e9;
	for(int i = 0; i < 100; i++) {
		double mi = (lo + hi) * 0.5;
		if(check(mi))
			lo = mi;
		else
			hi = mi;
	}
	cout << fixed << setprecision(10) << hi << endl;
}