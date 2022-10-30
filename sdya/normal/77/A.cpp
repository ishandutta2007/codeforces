#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <bitset>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 10;
map < string, int > M;
int g[maxN][maxN];
long long a, b, c;

vector < int > x, y, z;

long long best = 1000000000000000000LL, sim = 0;

int getSim(vector < int > a) {
	int res = 0;
	for (int i = 0; i < a.size(); ++i) {
		for (int j = 0; j < a.size(); ++j) {
			res += g[a[i]][a[j]];
		}
	}
	return res;
}

void rec(int have) {
	if (have == 7) {
		if (x.size() == 0 || y.size() == 0 || z.size() == 0) {
			return ;
		}
		long long u[3];
		u[0] = a / x.size();
		u[1] = b / y.size();
		u[2] = c / z.size();
		sort(u, u + 3);
		int curSim = getSim(x) + getSim(y) + getSim(z);
		if (u[2] - u[0] < best) {
			best = u[2] - u[0];
			sim = curSim;
		} else if (u[2] - u[0] == best && sim < curSim) {
			sim = curSim;
		}
		return ;
	}
	x.push_back(have + 1);
	rec(have + 1);
	x.pop_back();

	
	y.push_back(have + 1);
	rec(have + 1);
	y.pop_back();

	
	z.push_back(have + 1);
	rec(have + 1);
	z.pop_back();
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	M["Anka"] = 1;
	M["Chapay"] = 2;
	M["Cleo"] = 3;
	M["Troll"] = 4;
	M["Dracul"] = 5;
	M["Snowy"] = 6;
	M["Hexadecimal"] = 7;

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s1, s, s2;
		cin >> s1 >> s >> s2;
		g[M[s1]][M[s2]] = 1;
	}
	cin >> a >> b >> c;

	rec(0);

	cout << best << " " << sim << endl;

	return 0;
}