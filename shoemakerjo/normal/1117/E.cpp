#include <bits/stdc++.h>

using namespace std;

const int maxn = 10010;

int fi[maxn];
int se[maxn];
int ti[maxn];

int n;
string t;
const string alph = "abcdefghijklmnopqrstuvwxyz";

int res[3][maxn];
int perm[maxn];



int main() {
	
	cin >> t;
	n = t.length();

	for (int i = 1; i < n; i++) {
		fi[i] = fi[i-1];
		se[i] = se[i-1];
		ti[i] = ti[i-1];
		ti[i]++;
		if (ti[i] == 26) {
			ti[i] = 0;
			se[i]++;
			if (se[i] == 26) {
				se[i] = 0;
				fi[i]++;
			}
		}
	}

	string ask1 = "", ask2 = "", ask3 = "";
	for (int i = 0; i < n; i++) {
		ask1 += alph[fi[i]];
		ask2 += alph[se[i]];
		ask3 += alph[ti[i]];
	}
	string cv;
	cout << "? " << ask1 << endl;
	cin >> cv;
	for (int i = 0; i < n; i++) {
		res[0][i] = cv[i]-'a';
	}
	cout << "? " << ask2 << endl;
	cin >> cv;
	for (int i = 0; i < n; i++) {
		res[1][i] = cv[i]-'a';
	}
	cout << "? " << ask3 << endl;
	cin >> cv;
	for (int i = 0; i < n; i++) {
		res[2][i] = cv[i]-'a';
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (res[0][j] == fi[i] && 
				res[1][j] == se[i] && 
				res[2][j] == ti[i]) {
				perm[i] = j;
			} 
		}
	}
	cout <<"! ";
	for (int i = 0; i < n; i++) {
		cout << t[perm[i]];
	}
	cout << endl;

}