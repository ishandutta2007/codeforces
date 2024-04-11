#include<bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i<b; i++)
#define dep(i,a,b) for(int i = a-1; i>=b; i--)
#define makeUnique(vec) sort(all(vec)); vec.resize(unique(all(vec)) - vec.begin())
#define LOG_vec(vec, sep) for (int fl = 0; fl < vec.size(); fl++) { cout << vec[fl]<< sep; } cout << "\n";
#define LOG_ints(vec, sep) for (int fl = 0; fl < MAXSIZE; fl++) { cout << vec[fl]<< sep; } cout << "\n"
#define all(x) (x).begin(), (x).end()
#define LSB(i) ((i) & -(i))
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;


int main() {
	int r, c; cin >> r >> c;
	vector<vector<char>> vc(r);
	rep(i, 0, r) {
		vector<char> tmp(c);
		rep(j, 0, c) {
			cin >> tmp[j];
		}
		vc[i] = tmp;
	}
	rep(i, 0, r) {
		rep(j, 0, c) {
			if (vc[i][j] == '.') {
				vc[i][j] = 'D';
			}
			else if (vc[i][j] == 'W') {
				if (i != 0) {
					if (vc[i - 1][j] == 'S') {
						cout << "No\n";
						return 0;
					}
				}
				if (i != r - 1) {
					if (vc[i+1][j] == 'S') {
						cout << "No\n";
						return 0;
					}

				}
				if (j != 0) {
					if (vc[i][j-1] == 'S') {
						cout << "No\n";
						return 0;
					}

				}
				if (j != c - 1) {
					if (vc[i][j+1] == 'S') {
						cout << "No\n";
						return 0;
					}

				}
			}

		}
	}
	cout << "Yes\n";
	rep(i, 0, r) {
		rep(j, 0, c) {
			cout << vc[i][j];
		}
		cout << endl;
	}
}