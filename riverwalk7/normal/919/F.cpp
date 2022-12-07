#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
#include<vector>
#include<map>
#include<list>
#include<set>
#include<cstring>
#include<ctime>
#include<cmath>
#include<limits>
#include<iterator>
#include<functional>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<bitset>
#include<complex>

#define all(v) v.begin(), v.end()
#define setv(ar, val) memset(ar, val, sizeof(ar));
#define ll long long int
#define ull unsigned long long int
#define PI 3.1415926535897932384626433832795
using namespace std;

#define vv(a, b) a[b[0]][b[1]][b[2]][b[3]][b[4]][b[5]][b[6]][b[7]]

int t[9][9][9][9][9][9][9][9], w[9][9][9][9][9][9][9][9], h[9][9][9][9][9][9][9][9];
queue<int> q;

void han(vector<int> &z, int x) {
	int m = 0;
	for (int k = 0; k < 8; k++)
		m = m * 10 + z[k];

	if (vv(t, z) == -1) {
		if (x) {
			vv(h, z)++;
			if (vv(h, z) == vv(w, z)) {
				vv(t, z) = 0;
				q.push(m);
			}
		}
		else {
			vv(t, z) = 1;
			q.push(m);
		}
	}
}

void rInt(int &a) {
	a = 0;
	char c = getchar();
	while (c < '0' || c > '9')
		c = getchar();
	while (c >= '0' && c <= '9') {
		a = a * 10 + c - '0';
		c = getchar();
	}
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	

	setv(t, -1);


	vector<int> g(8);
	for (g[0] = 0; g[0] < 9; g[0]++)
		for (g[1] = 0; g[1] < 9; g[1]++)
			for (g[2] = 0; g[2] < 9; g[2]++)
				for (g[3] = 0; g[3] < 9; g[3]++) {
					if (g[0] + g[1] + g[2] + g[3] > 8)
						break;
					for (g[4] = 0; g[4] < 9; g[4]++)
						for (g[5] = 0; g[5] < 9; g[5]++)
							for (g[6] = 0; g[6] < 9; g[6]++)
								for (g[7] = 0; g[7] < 9; g[7]++) {

									if (g[4] + g[5] + g[6] + g[7] > 8)
										break;

									for (int i = 0; i < 4; i++)
										for (int j = 0; j < 4; j++)
											if (g[i] && g[j + 4]) {
												vv(w, g)++;
											}



								}
				}

	
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			for (int k = 0; k < 9; k++)
				for (int g = 0; g < 9; g++) {
					t[i][j][k][g][0][0][0][0] = 0;
					if (i + j + k + g <= 8)
						q.push(i * 1e7 + j * 1e6 + k * 1e5 + g * 1e4);
				}


	while (!q.empty()) {
		int m = q.front();
		q.pop();

		for (int i = 7; i >= 0; i--, m /= 10)
			g[i] = m % 10;

		int x = vv(t, g);
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (!g[i + 4] || !g[j])
					continue;
				int d = (i - j + 5);
				if (d >= 5)
					d -= 5;

				if (!d)
					continue;
				vector<int> z = g;
				z[i + 4]--;
				z[d + 3]++;
					
				for (int k = 0; k < 4; k++)
					swap(z[k], z[k + 4]);

				han(z, x);
			}
		}

		if (g[4] + g[5] + g[6] + g[7] < 8) {
			for (int j = 0; j < 4; j++) {
				if (!g[j])
					continue;
				vector<int> z = g;
				int d = (4 - j);
				z[d + 3]++;

				for (int k = 0; k < 4; k++)
					swap(z[k], z[k + 4]);

				han(z, x);
			}
		}

	}


	int s;
	scanf("%d", &s);
	while (s--) {
		int f;
		scanf("%d", &f);

		int a[8];
		setv(a, 0);
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 8; j++) {
				int c;
				rInt(c);
				if (c)
					a[(f ^ i) * 4 + c - 1]++;
			}
		if (vv(t, a) == -1)
			printf("Deal\n");
		else if (vv(t, a)) {
			printf("%s\n", f ? "Bob" : "Alice");
		}
		else
			printf("%s\n", f ? "Alice" : "Bob");
	}



	return 0;
}