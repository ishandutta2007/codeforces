#include<bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i<b; i++)
#define dep(i,a,b) for(int i = a; i>b; i--)
#define makeUnique(vec) sort(all(vec)); vec.resize(unique(all(vec)) - vec.begin())
#define in(name, type) type name; cin >> name
#define LOG(x, sep) std::cout << x << sep
#define LOG(x) std::cout << x << "\n"
#define LOG_vec(vec, sep) for (int fl = 0; fl < vec.size(); fl++) { std::cout << vec[fl] << sep; } std::cout << "\n"
#define all(x) (x).begin(), (x).end()
#define ll long long
using namespace std;

int main() {

	int t;
	cin >> t;
	rep(i, 0, t) {
		int x, y;
		cin >> x >> y;

		if (x > y) {
			if (x % 2 == y % 2) {
				cout << 1 << "\n";
			}
			else {
				cout << 2 << "\n";
			}
		}
		else if (y > x) {
			if (x % 2 == y % 2) {
				cout << 2 << "\n";
			}
			else {
				cout << 1 << "\n";
			}
		}
		else {
			cout << 0 << "\n";
		}


	}
	return 0;
}