#include<bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i<b; i++)
#define dep(i,a,b) for(int i = a; i>b; i--)
#define makeUnique(vec) sort(all(vec)); vec.resize(unique(all(vec)) - vec.begin())
#define LOG_vec(vec, sep) for (int fl = 0; fl < vec.size(); fl++) { std::cout << vec[fl]<< sep; } std::cout << "\n";
#define LOG_ints(vec, sep) for (int fl = 0; fl < MAXSIZE; fl++) { std::cout << vec[fl]<< sep; } std::cout << "\n"
#define all(x) (x).begin(), (x).end()
#define ll long long
#define LSB(i) ((i) & -(i))
#define MAXSIZE 100000000

using namespace std;
vector<vector<int>>grid;
queue<pair<int, int>> q;
int n, m;
int secondres = 0;
void solve() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int x, y, x1, y1, x2, y2;
	cin >> x >> y >> x1 >> y1 >> x2 >> y2;
	x -= a;
	x += b;
	y -= c;
	y += d;
	if (x1 == x2) {
		if (a > 0 || b > 0) {
			cout << "No\n";
			return;
		}
	}
	if (y1 == y2) {
		if (c > 0 || d > 0) {
			cout << "No\n";
			return;
		}
	}
	if (x1 <= x && x <= x2 && y1 <= y && y <= y2) {
		cout << "Yes\n";
		return;
	}
	cout << "No\n";
	return;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}

}