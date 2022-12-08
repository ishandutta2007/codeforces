#include <bits/stdc++.h>

using namespace std;
#define pii pair<int, int>
#define pp pair<pii, pii>
#define mp make_pair

#define maxn 301
int n, m;
deque<int> cur[maxn][maxn];

vector<pp> ans; //just store all operations here

vector<int> fstate[maxn][maxn];

void go(int x1, int y1, int x2, int y2) {

	// cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;

	// assert(x1 != x2 || y1 != y2);
	// assert(x1 == x2 || y1 == y2);

	ans.push_back(mp(mp(x1, y1), mp(x2, y2)));
	cur[x2][y2].push_front(cur[x1][y1].back());
	cur[x1][y1].pop_back();
}
void clearout(int x1, int y1) {
	while (cur[x1][y1].size()) {
		int val = cur[x1][y1].back();
		if (val == 0) {
			if (x1 == 1 || y1 == 1) {
				go(x1, y1, 1, 1);
			}
			else {
				if (x1 == n) {
					go(x1, y1, n, 1);
					go(n, 1, 1, 1);
				}
				else if (y1 == m) {
					go(x1, y1, 1, m);
					go(1, m, 1, 1);
				}
				else {
					go(x1, y1, x1, 1);
					go(x1, 1, 1, 1);
				}
			}

		}
		else {
			if (x1 == n || y1 == m) {
				go(x1, y1, n, m);
			}
			else {
				if (x1 == 1) {
					go(x1, y1, 1, m);
					go(1, m, n, m);
				}
				else if (y1 == 1) {
					go(x1, y1, n, 1);
					go(n, 1, n, m);
				}
				else {
					go(x1, y1, x1, m);
					go(x1, m, n, m);
				}
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	string val;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> val;
			for (int k = 0; k < val.size(); k++) {
				cur[i][j].push_back(val[k] - '0');
			}
		}

	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> val;
			for (int k = 0; k < val.size(); k++) {
				fstate[i][j].push_back(val[k]-'0');
			}
		}
	}

	int tlsize = cur[1][1].size();
	int brsize = cur[n][m].size();

	// cout << "HERE HERE HERE" << endl;

	clearout(1, m);
	clearout(n, 1);

	// cout << "CONERS CLEARED" << endl;

	for (int i = 2; i < n; i++) {
		clearout(i, 1);
		clearout(i, m);
	}
	for (int i = 2; i < m; i++) {
		clearout(1, i);
		clearout(n, i);
	}

	for (int i = 2; i < n; i++) {
		for (int j = 2; j < m; j++) {
			clearout(i, j);
		}
	}


	// cout << "ALL CLEAR" << endl;

	for (int i = 0; i < tlsize; i++) {
		//take it off, and add it to correct spot
		int val = cur[1][1].back();
		if (val == 0) {
			go(1, 1, n, 1);
			go(n, 1, 1, 1);
		}
		else {
			go(1, 1, n, 1);
			go(n, 1, n, m);
		}
	}
	for (int i = 0; i < brsize; i++) {
		int val = cur[n][m].back();
		if (val == 0) {
			go(n, m, n, 1);
			go(n, 1, 1, 1);
		}
		else {
			go(n, m, n, 1);
			go(n, 1, n, m);
		}
	}

	// if (!(n == 2 && m == 2 || n == 2 && m == 3)) return 0;
	//ABOVE DOES NOT INDUCE RTE

	//now we have all 0's in tl and all 1's in br
	for (int i = 2; i < n; i++) {
		for (int j = 2; j < m; j++) {
			//fill in the middle
			for (int k = fstate[i][j].size()-1; k >= 0; k--) {
				int cval = fstate[i][j][k];
				if (cval == 0) {
					//grab me a 0
					go(1, 1, i, 1);
					go(i, 1, i, j);
				}
				else {
					go(n, m, i, m);
					go(i, m, i, j);
				}
			}
		}
	}
	//we have now filled in the center block

	//fill in left column
	for (int i = 2; i < n; i++) {
		for (int k = fstate[i][1].size()-1; k >= 0; k--) {
			int cval = fstate[i][1][k];

			if (cval == 0) {
				go(1, 1, i, 1);
			}
			else {
				go(n, m, n, 1);
				go(n, 1, i, 1);
			}
		}

		for (int k = fstate[i][m].size()-1; k >= 0; k--) {
			int cval = fstate[i][m][k];
			if (cval == 0) {
				go(1, 1, 1, m);
				go(1, m, i, m);
			}
			else {
				go(n, m, i, m);
			}
		}
	}
	for (int j = 2; j < m; j++) {
		for (int k = fstate[1][j].size()-1; k >= 0; k--) {
			int cval = fstate[1][j][k];

			if (cval == 0) {
				go(1, 1, 1, j);
			}
			else {
				go(n, m, 1, m);
				go(1, m, 1, j);
			}

		}


		for (int k = fstate[n][j].size()-1; k >= 0; k--) {
			int cval = fstate[n][j][k];

			if (cval == 0) {
				go(1, 1, n, 1);
				go(n, 1, n, j);
			}
			else {
				go(n, m, n, j);
			}
		}
	}

	//now we build up block b
	for (int k = fstate[1][m].size()-1; k >= 0; k--) {
		int cval = fstate[1][m][k];
		if (cval == 0) {
			go(1, 1, 1, m);
		}
		else {
			go(n, m, 1, m);
		}
	}

	//now, we build up a on d and then c on d
	for (int k = fstate[1][1].size()-1; k >= 0; k--) {
		int cval = fstate[1][1][k];
		if (cval == 0) {
			go(1, 1, n, 1);
		}
		else {
			go(n, m, n, 1);
		}
	}
	for (int k = fstate[n][m].size()-1; k >= 0; k--) {
		int cval = fstate[n][m][k];
		if (cval == 0) {
			go(1, 1, n, 1);
		}
		else {
			go(n, m, n, 1);
		}
	}
	for (int k = fstate[n][1].size()-1; k >= 0; k--) {
		int cval = fstate[n][1][k];
		if (cval == 0) {
			go(1, 1, n, 1);
		}
		else {
			go(n, m, n, 1);
		}
	}

	for (int k = fstate[1][1].size()-1; k >= 0; k--) {
		go(n, 1, 1, 1);
	}
	for (int k = fstate[n][m].size()-1; k >= 0; k--) {
		go(n, 1, n, m);
	}


	cout << ans.size() << '\n';
	for (pp x : ans) {
		cout << x.first.first << " " << x.first.second << " " << 
			x.second.first << " " << x.second.second << '\n';
	}
	cout.flush();

	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 1; j <= m; j++) {
	// 		while (cur[i][j].size()) {
	// 			cout << cur[i][j].front();
	// 			cur[i][j].pop_front();
	// 		}
	// 		cout << " ";
	// 	}
	// 	cout << endl;
	// }
	
}