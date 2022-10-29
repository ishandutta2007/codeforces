#include<bits/stdc++.h>
#include<unordered_set>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define LSB(i) ((i) & -(i))
#define MAXSIZE 100000000

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }

void solveA() {
	int n,a,b,c,d; cin >> n >> a >> b >> c >> d;
	cout << ((a - b) * n <= (c + d) && (a + b) * n>=(c - d) ? "YES\n" : "NO\n");
}
void solveB() {
	int n, k; cin >> n >> k;
	vi v(n);
	int curr = 0, best,best2 = 1;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = 1; i < k-1; i++) {
		if (v[i] > v[i - 1] && v[i] > v[i + 1]) {
			curr++;
		}
	}
	best = curr;
	for (int i = 2; i < n - k+2; i++) {
		if (v[i - 1] > v[i - 2] && v[i - 1] > v[i]) {
			curr--;
		}
		if (v[i +k-3] > v[i + k -2] && v[i + k-3] > v[i +k-4]) {
			curr++;
		}
		if (curr > best) {
			best = curr;
			best2 = i;
		}

	}
	cout << best+1 << " " << best2 << "\n";

}
void solveC() {

}
void solveD() {

}
void solveE() {

}
void solveF() {

}

int main() {

	ios::sync_with_stdio(0); cin.tie(0);

	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int t; cin >> t;

	while (t--) {
		solveB();
	}
	return 0;
}