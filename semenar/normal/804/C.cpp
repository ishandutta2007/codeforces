#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <iomanip>
#include <cmath>
#include <ctime>

#pragma comment(linker, "/STACK:134217728")

using namespace std;

#define INF 1e9
#define PI 3.1415927
#define P 1000000007

long long gcd(long long m, long long n) {
	return ((n == 0) ? m : gcd(n, m%n));
}

vector<vector<int>> gr;
vector<vector<int>> icecream;
vector<int> colors;
vector<bool> vis;
int max_colour = 1;

void hang(int x) {
	vis[x] = true;
	set<int> colour;
	for (int i = 0; i < icecream[x].size(); i++) {
		if (colors[icecream[x][i]] > 0) colour.insert(colors[icecream[x][i]]);
	}
	int pos = 1;
	for (int i = 0; i < icecream[x].size(); i++) {
		if (colors[icecream[x][i]] == 0) {
			while (colour.find(pos) != colour.end()) pos++;
			colors[icecream[x][i]] = pos;
			max_colour = max(max_colour, pos);
			pos++;
		}
	}
	for (int v : gr[x]) if (!vis[v]) hang(v);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	gr.resize(n);
	icecream.resize(n);
	vis.resize(n);
	colors.resize(m);

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		icecream[i].resize(tmp);

		for (int j = 0; j < tmp; j++) {
			cin >> icecream[i][j];
			icecream[i][j]--;
		}
	}

	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		gr[a].push_back(b);
		gr[b].push_back(a);
	}

	hang(0);

	for (int i = 0; i < m; i++) {
		if (colors[i] == 0) colors[i] = 1;
	}

	cout << max_colour << endl;
	for (int i = 0; i < m; i++) cout << colors[i] << ' ';

	return 0;
}