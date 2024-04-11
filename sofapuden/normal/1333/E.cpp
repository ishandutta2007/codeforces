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
	int n;
	cin >> n;
	if (n <= 2) {
		cout << -1 << endl;
	}
	else {
		vi tmp(n, 0);
		vector<vi> grid(n, tmp);
		
		int currind = 1;
		rep(i, 3, n) {
			if (i % 2 == 1) {
				rep(j, 0, i) {
					grid[j][i] = currind;
					currind++;
				}
				grid[i][i] = currind;
				currind++;
				dep(j, i - 1, -1) {
					grid[i][j] = currind;
					currind++;
				}
			}
			else {
				rep(j, 0, i) {
					grid[i][j] = currind;
					currind++;
				}
				grid[i][i] = currind;
				currind++;
				dep(j, i - 1, -1) {
					grid[j][i] = currind;
					currind++;
				}
			}
		}
		grid[0][0] = currind;
		grid[1][0] = currind + 1;
		grid[2][0] = currind + 7;
		grid[0][1] = currind + 6;
		grid[1][1] = currind + 2;
		grid[2][1] = currind + 3;
		grid[0][2] = currind + 5;
		grid[1][2] = currind + 4;
		grid[2][2] = currind + 8;
		rep(i, 0, grid.size()) {
			rep(j, 0, grid[i].size()) {
				cout << grid[i][j] << " "; 
			}
			cout << endl;
		}
	}
}