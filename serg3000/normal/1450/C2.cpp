#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <set>
#include <queue>
#include <deque>
#include <unordered_set>
#include <map>
#include<unordered_map>
#include <bitset>
#include <random>
#include <ctime>
#include <fstream>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("vpt")
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define firn(i, n) for (int i = 1; i < (int)n; i++)
#define all(v) v.begin(), v.end()
mt19937 rnd(time(nullptr));
//#define int long long
using namespace std;
vector<vector<int>>g;
signed main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	forn(w, t) {
		int n;
		cin >> n;
		vector<vector<int>>a(n, vector<int>(n));
		forn(i, n) {
			forn(j, n) {
				char x;
				cin >> x;
				if (x == 'O') {
					a[i][j] = 1;
				}
				if (x == 'X') {
					a[i][j] = 2;
				}
			}
		}
		vector<int>c(3);
		vector<int>c2(3);
		vector<int>c3(3);
		forn(i, n) {
			forn(j, n) {
				if (a[i][j] != 0) {
					c[(i + j) % 3]++;
					if (a[i][j] == 1) {
						c2[(i + j) % 3]++;
					}
					else {
						c3[(i + j) % 3]++;
					}
				}
			}
		}
		if (c[0] >= c[1] && c[0] >= c[2]) {
			if (c2[1] + c3[2] <= c2[2] + c3[1]) {
				forn(i, n) {
					forn(j, n) {
						if (a[i][j] != 0) {
							if ((i + j) % 3 == 1) {
								a[i][j] = 2;
							}
							if ((i + j) % 3 == 2) {
								a[i][j] = 1;
							}
						}
					}
				}
			}
			else {
				forn(i, n) {
					forn(j, n) {
						if (a[i][j] != 0) {
							if ((i + j) % 3 == 1) {
								a[i][j] = 1;
							}
							if ((i + j) % 3 == 2) {
								a[i][j] = 2;
							}
						}
					}
				}
			}
		}
		else {
			if (c[1] >= c[0] && c[1] >= c[2]) {
				if (c2[0] + c3[2] <= c2[2] + c3[0]) {
					forn(i, n) {
						forn(j, n) {
							if (a[i][j] != 0) {
								if ((i + j) % 3 == 0) {
									a[i][j] = 2;
								}
								if ((i + j) % 3 == 2) {
									a[i][j] = 1;
								}
							}
						}
					}
				}
				else {
					forn(i, n) {
						forn(j, n) {
							if (a[i][j] != 0) {
								if ((i + j) % 3 == 0) {
									a[i][j] = 1;
								}
								if ((i + j) % 3 == 2) {
									a[i][j] = 2;
								}
							}
						}
					}
				}
			}
			else {
				if (c[2] >= c[0] && c[2] >= c[0]) {
					if (c2[0] + c3[1] <= c2[1] + c3[0]) {
						forn(i, n) {
							forn(j, n) {
								if (a[i][j] != 0) {
									if ((i + j) % 3 == 0) {
										a[i][j] = 2;
									}
									if ((i + j) % 3 == 1) {
										a[i][j] = 1;
									}
								}
							}
						}
					}
					else {
						forn(i, n) {
							forn(j, n) {
								if (a[i][j] != 0) {
									if ((i + j) % 3 == 0) {
										a[i][j] = 1;
									}
									if ((i + j) % 3 == 1) {
										a[i][j] = 2;
									}
								}
							}
						}
					}
				}

			}
		}

		forn(i, n) {
			forn(j, n) {
				if (a[i][j] == 0) {
					cout << '.';
				}
				if (a[i][j] == 2) {
					cout << 'X';
				}
				if (a[i][j] == 1) {
					cout << 'O';
				}
			}
			cout << '\n';
		}
	}
	return 0;
}