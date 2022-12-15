#include <bits/stdc++.h>

using namespace std;

bool query(int x1, int y1, int x2, int y2){
	++x1, ++y1, ++x2, ++y2;

	cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
	fflush(stdout);

	bool ans;
	cin >> ans;
	//fflush(stdout);

	return ans;
}

const int MAXN = 57;

bool a[MAXN][MAXN];
pair<bool, bool> dp[MAXN][MAXN][MAXN][MAXN][2];

bool get_val(int x, int y, bool b){
	if((x + y) & 1){
		return (a[x][y] ^ b);
	}

	return a[x][y];
}

bool solve(int x1, int y1, int x2, int y2, bool b){
	pair<bool, bool> &p = dp[x1][y1][x2][y2][b];

	if(x1 > x2 || y1 > y2){
		return false;
	}
	if(x1 == x2 && y1 == y2){
		return true;
	}
	if(get_val(x1, y1, b) != get_val(x2, y2, b)){
		return false;
	}
	if(x1 + y1 + 1 == x2 + y2){
		return true;
	}
	if(p.second){
		return p.first;
	}

	p.second = true;
	p.first = false;

	if(solve(x1 + 1, y1, x2 - 1, y2, b)){
		p.first = true;
		return true;
	}
	if(solve(x1 + 1, y1, x2, y2 - 1, b)){
		p.first = true;
		return true;
	}
	if(solve(x1, y1 + 1, x2 - 1, y2, b)){
		p.first = true;
		return true;
	}
	if(solve(x1, y1 + 1, x2, y2 - 1, b)){
		p.first = true;
		return true;
	}

	return false;
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);

	int n;

	cin >> n;

	a[0][0] = true;
	a[0][1] = false;
	a[2][1] = (bool)(a[0][1] == query(0, 1, 2, 1));
	a[1][0] = (bool)(a[2][1] == query(1, 0, 2, 1));

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if((i == 0 && j == 0) || (i == n - 1 && j == n - 1) || (i == 0 && j == 1) || (i == 2 && j == 1) || (i == 1 && j == 0)){
				continue;
			}
			int x, y;

			if(i > 0 && j > 0){
				x = i - 1;
				y = j - 1;
			}
			else{
				if(i == 0){
					x = i;
					y = j - 2;
				}
				if(j == 0){
					x = i - 2;
					y = j; 
				}
			}

			a[i][j] = (bool)(a[x][y] == query(x, y, i, j));
		}
	}

	for(int x1 = 0; x1 < n; ++x1){
		for(int y1 = 0; y1 < n; ++y1){
			for(int x2 = x1; x2 < n; ++x2){
				for(int y2 = y1; y2 < n; ++y2){
					if(x1 + y1 + 2 > x2 + y2){
						continue;
					}

					for(int b = 0; b < 2; b++){
						solve(x1, y1, x2, y2, b);
					}

					if(solve(x1, y1, x2, y2, false) != solve(x1, y1, x2, y2, true)){
						bool t = query(x1, y1, x2, y2);

						if(t == solve(x1, y1, x2, y2, false)){
							cout << "!" << endl;
							fflush(stdout);
							for(int i = 0; i < n; i++){
								for(int j = 0; j < n; j++){
									cout << a[i][j];
									fflush(stdout);
								}
								cout << endl;
								fflush(stdout);
							}
							fflush(stdout);

							return 0;
						}
						else{
							cout << "!" << endl;
							for(int i = 0; i < n; i++){
								for(int j = 0; j < n; j++){
									if((i + j) & 1){
										cout << (!a[i][j]);
										continue;
									}

									cout << a[i][j];
								}
								cout << endl;
								fflush(stdout);
							}
							fflush(stdout);

							return 0;
						}
					}
				}
			}
		}
	}

	cout << "!" << endl;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << a[i][j];
		}
		cout << endl;
	}
	fflush(stdout);

	return 0;
}