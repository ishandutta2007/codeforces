#include<bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i<b; i++)
#define dep(i,a,b) for(int i = a; i>b; i--)
#define makeUnique(vec) sort(all(vec)); vec.resize(unique(all(vec)) - vec.begin())
#define LOG_vec(vec, sep) for (int fl = 0; fl < vec.size(); fl++) { std::cout << vec[fl]<< sep; } std::cout << "\n"
#define LOG_ints(vec, sep) for (int fl = 0; fl < MAXSIZE; fl++) { std::cout << vec[fl]<< sep; } std::cout << "\n"
#define all(x) (x).begin(), (x).end()
#define ll long long
#define LSB(i) ((i) & -(i))
#define MAXSIZE 100000000


using namespace std;

void solve() {
	int n;
	cin >> n;
	bool ok = 0;
	if (n == 1) {
		int tmp;
		cin >> tmp;
		if (tmp % 2 == 1) {
			cout << -1 << "\n";
			return;
		}
		else {
			cout << 1 << "\n" << 1 << "\n";
		}
	}
	else {
		rep(i, 0, n) {
			int tmp;
			cin >> tmp;
			if (i == 0) {
				if (tmp % 2 == 1) {
					ok = 1;
				}
				else {
					cout << 1 << "\n" << 1 << "\n";
				}
			}
			else if (i == 1 && ok == 1) {
				if (tmp % 2 == 1) {
					cout << 2 << "\n" << 1 << " " << 2 << "\n";
				}
				else {
					cout << 1 << "\n" << 2 << "\n";
				}
			}
		}

	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}