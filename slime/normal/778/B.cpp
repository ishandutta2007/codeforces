#include <bits/stdc++.h>
#define ll long long
#define maxn 5005 /*rem*/
#define mod 1000000007 
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
map<string, int> id;
int df[maxn][3]; //  -1 :  0  and 1  or 2  xor id[0] id[1]
int tr[maxn][1005]; // 
int fn[2][1005];
int c[maxn];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string x; 
		cin >> x;
		id[x] = i;
		string t;
		cin >> t;
		cin >> t;
		if (t[0] == '0' || t[0] == '1') {
			df[i][0] = -1;
			for (int j = 0; j < m; j++)
				tr[i][j] = t[j] - '0';
		}
		else {
			if (t[0] == '?') df[i][1] = 0;
			else df[i][1] = id[t];
			cin >> t;
			if (t[0] == 'X') df[i][0] = 2;
			else if (t[0] == 'A') df[i][0] = 0;
			else if (t[0] == 'O') df[i][0] = 1;
			cin >> t;
			if (t[0] == '?')
				df[i][2] = 0;
			else df[i][2] = id[t];
		}
	}
	for (int i = 0; i < m; i++) {
		int r[2] = {0, 0};
		for (int j = 0; j < 2; j++) {
			c[0] = j;
			for (int k = 1; k <= n; k++) {
				if (df[k][0] == -1) c[k] = tr[k][i];
				else {
					int v[2] = {c[df[k][1]], c[df[k][2]]};
					if (df[k][0] == 0) c[k] = v[0] & v[1];
					else if (df[k][0] == 1) c[k] = v[0] | v[1];
					else c[k] = v[0] ^ v[1];
				}
				r[j] += c[k];
			}
		}
		if (r[1] > r[0]) fn[1][i] = 1;
		if (r[1] < r[0]) fn[0][i] = 1; 
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < m; j++)
			printf("%c", '0' + fn[i][j]);
		printf("\n");
	}
 	return 0;
}