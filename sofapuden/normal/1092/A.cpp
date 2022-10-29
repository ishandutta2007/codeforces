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
	int n, k;
	cin >> n >> k;
	char tmp = 'a'-1;
	rep(i, 0, k) {
		tmp += 1;
		rep(i, 0, n / k) {
			cout << tmp;
		}
	}
	rep(i, 0, n% k) {
		cout << 'a';
	}
	cout << endl;
	return;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}