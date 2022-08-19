#include <bits/stdc++.h>
#define ll long long
#define maxn 200005 /*rem*/
#define db double
#define vi vector<int>
#define pb push_back
#define pi pair<int, int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
int rd;
int n, k;
int ask(int x) {
	cout << "? " <<  x << endl;
	fflush(stdout);
	int res;
	cin >> res;
	rd++;
	if (res > k) return 1;
	else if (res < k) return -1;
	else return 0;
}
void otp(int s) {
	while (s <= 0) s += n;
	while (s > n) s -= n;
	cout << "! " << s << endl;
	fflush(stdout);
	exit(0);
}
int main() {
	cin >> n >> k;
	if (n < 990) {
		for (int i = 1; i <= n + 1; i++) {
			int cur = ask(1);
			if (cur != 0) {
				rd--;
				otp(1 - cur * rd);
			}
		}
		if (n % 2 == 0)
			if (ask(2) == 1) otp(1);
			else otp(1 + n / 2);
		else otp(1);
	}
	int ed = sqrt(n) - 10;
	int dv = n / ed + 5;
	vi cur;
	int pl = 1;
	while (pl <= n)
		cur.pb(pl), pl += dv;
	while (1) {
		for (int t = 0; t < cur.size(); t++) {
			int h = cur[t];
			int res = ask(h);
			if (res == 1) {
				int nx = cur[(t + 1) % cur.size()];
				while (1) {
					if (ask(nx) == 1)
						rd--, 
						otp(nx - rd);
				}
			}
		}
	}
	return 0;
}
/*
5 4
0 1 2 3

*/