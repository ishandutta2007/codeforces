#include <bits/stdc++.h>

using namespace std;
#define maxn 2010

int n, a, b;
double pa[maxn];
double pb[maxn];
double dp[maxn];
double pboth[maxn];
double curans; //will be dp[n]
int at, bt;

int go2(double bcost, double acost) {
	dp[0] = 0.0;
	at = 0;
	bt = 0;
	for (int i = 1; i <= n; i++) {
		int otake = 0; //option taken
		dp[i] = dp[i-1];
		if (dp[i-1] + pa[i] - acost > dp[i]) {
			dp[i] = dp[i-1] + pa[i] - acost;
			otake = 1;
		}
		if (dp[i-1] + pb[i] - bcost > dp[i]) {
			dp[i] = dp[i-1] + pb[i] - bcost;
			otake = 2;
		}
		if (dp[i-1] + pboth[i] - acost - bcost > dp[i]) {
			dp[i] = dp[i-1] + pboth[i] - acost - bcost;
			otake = 3;
		}
		if (otake == 1 || otake == 3) at++;
		if (otake == 2 || otake == 3) bt++;
	}
	return bt;
}

int go(double acost) {
	double lo = 0.0;
	double hi = 1.0;
	for (int i = 0; i < 50; i++) {
		double mid = (lo+hi)/2.0;
		int btake = go2(mid, acost);
		if (btake > b) { //took too many, incrase the cost
			lo = mid;
		}
		else { //took too few or an okay amount
			hi = mid;
		}
	}
	// cout << "lo: " << lo << endl;
	go2(hi, acost);
	dp[n] += hi*b;
	return at;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(10);

	cin >> n >> a >> b;
	for (int i = 1; i <= n; i++) {
		cin >> pa[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> pb[i];
	}
	for (int i = 1; i <= n; i++) {
		pboth[i] = 1.0 - (1.0 - pa[i]) * (1.0 - pb[i]);
	}

	double lo = 0.0;
	double hi = 1.0;
	for (int i = 0; i < 50; i++) {
		double mid = (lo+hi)/2.0;
		int atake = go(mid);
		if (atake > a) {
			lo = mid;
		}
		else hi = mid;

	}
	go(hi);
	double ans = dp[n] + hi * a;
	// cout << "lo: " << lo << endl;
	cout << ans << endl;
	cin >> n;
}