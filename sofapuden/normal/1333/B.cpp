#include<bits/stdc++.h>
#include<unordered_set>
#define rep(i,a,b) for(int i = a; i<b; i++)
#define dep(i,a,b) for(int i = a; i>b; i--)
#define makeUnique(vec) sort(all(vec)); vec.resize(unique(all(vec)) - vec.begin())
#define LOG_vec(vec, sep) for (int fl = 0; fl < vec.size(); fl++) { std::cout << vec[fl]<< (fl == vec.size()-1?"\n":sep;)}
#define LOG_ints(vec, sep) for (int fl = 0; fl < MAXSIZE; fl++) { std::cout << vec[fl]<< sep; } std::cout << "\n"
#define all(x) (x).begin(), (x).end()
#define LSB(i) ((i) & -(i))
#define MAXSIZE 10

using namespace std;
typedef long long ll;
typedef vector<int> vi;
void solve() {
	int n;
	cin >> n;
	vi a;
	vi b;
	bool check[5];
	check[1] = 0;
	check[2] = 0;
	rep(i, 0, n) {
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
	}
	rep(i, 0, n) {
		int tmp;
		cin >> tmp;
		b.push_back(tmp);
	}
	rep(i, 0, n) {
		if (a[i] < b[i]) {
			if (check[2] != 1) {
				cout << "NO\n";
				return;
			}
		}
		else if (a[i] > b[i]) {
			if (check[1] != 1) {
				cout << "NO\n";
				return;
			}
		}
		if (a[i] == 1) {
			check[2] = 1;
		}
		else if (a[i] == -1) {
			check[1] = 1;
		}
	}
	cout << "YES\n";
	return;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}