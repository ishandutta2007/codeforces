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

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		if (n != 1 && m != 1) {
			rep(i, 0, n) {
				rep(j, 0, m) {
					cout << (i == 0 && j == 0 ? "W" : "B");
				}
				cout << endl;
			}
		}
		else {
			rep(i, 0, n) {
				rep(j, 0, m) {
					cout << (i == 1 || j == 1 ? "W" : "B");
				}
				cout << endl;
			}
		}
	}
}