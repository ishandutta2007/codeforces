#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <cmath>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

string words[10];
int b[10], c[10], a[10];

map < string, string > M;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	//std::ios_base::sync_with_stdio(false);
	
	set < string > S;
	for (int i = 1; i <= 2; ++i) {
		for (int j = 1; j <= 2; ++j) {
			for (int k = 1; k <= 2; ++k) {
				for (int l = 1; l <= 2; ++l) {
					char s[15];
					for (int f = 0; f < 10; ++f) {
						s[f] = 0;
					}
					sprintf(s, "%d%d%d%d%d%d\n", (i != j), (i != k), (i != l), (j != k), (j != l), (k != l));
					string res = "";
					for (int f = 0; f < 6; ++f) {
						res += s[f];
					}
					S.insert(res);
					string r = "";
					r += 'a' + i - 1;
					r += 'a' + j - 1;
					r += 'a' + k - 1;
					r += 'a' + l - 1;
					M[res] = r;
				}
			}
		}
	}

	int n = 0;
	for (set < string > :: iterator it = S.begin(); it != S.end(); ++it) {
		words[n ++] = * it;
	}

	for (int i = 1; i <= 6; ++i) {
		cin >> b[i];
	}
	

	int res = 1000000000, need = -1;
	for (int i = 0; i <= 1000000; ++i) {
		c[1] = 2 * i;
		c[2] = b[4] + c[1] - b[3] - b[5] + b[2];
		c[3] = - c[1] - b[1] + b[3] + b[5];
		c[4] = b[1] + c[1] - b[3] - b[6] + b[4];
		c[5] = - c[1] + b[3] - b[2] + b[6];
		c[6] = - b[4] - c[1] + b[5] + b[6];
		c[7] = b[1] + b[2] - b[6] + c[1] - b[5];

		bool good = true;
		for (int j = 1; j <= 7; ++j) {
			if (c[j] < 0) {
				good = false;
			}
			if (c[j] % 2 != 0) {
				good = false;
			}
		}
		if (good) {
			int cur = 0;
			for (int j = 1; j <= 7; ++j) {
				cur += c[j] / 2;
			}
			if (cur < res) {
				res = cur;
				need = i;
			}
		}
	}

	if (need == -1) {
		cout << -1 << endl;
	} else {
		cout << res << endl;
		string s1 = "", s2 = "", s3 = "", s4 = "";
		c[1] = 2 * need;
		c[2] = b[4] + c[1] - b[3] - b[5] + b[2];
		c[3] = - c[1] - b[1] + b[3] + b[5];
		c[4] = b[1] + c[1] - b[3] - b[6] + b[4];
		c[5] = - c[1] + b[3] - b[2] + b[6];
		c[6] = - b[4] - c[1] + b[5] + b[6];
		c[7] = b[1] + b[2] - b[6] + c[1] - b[5];

		for (int i = 1; i <= 7; ++i) {
			a[i] = c[i] / 2;
			string cur = M[words[i]];
			for (int j = 0; j < a[i]; ++j) {
				s1 += cur[0];
				s2 += cur[1];
				s3 += cur[2];
				s4 += cur[3];
			}
		}
		cout << s1 << endl;
		cout << s2 << endl;
		cout << s3 << endl;
		cout << s4 << endl;
	}



	return 0;
}