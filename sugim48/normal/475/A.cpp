#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cstring>
#include <climits>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

int main() {
	vector<string> s(6);
	s[0] = "+------------------------+";
	s[1] = "|#.#.#.#.#.#.#.#.#.#.#.|D|)";
	s[2] = "|#.#.#.#.#.#.#.#.#.#.#.|.|";
	s[3] = "|#.......................|";
	s[4] = "|#.#.#.#.#.#.#.#.#.#.#.|.|)";
	s[5] = "+------------------------+";
	int k; cin >> k;
	for (int j = 0; k > 0; j++)
		for (int i = 0; k > 0 && i < 6; i++)
			if (s[i][j] == '#') {
				s[i][j] = 'O';
				k--;
			}
	for (int i = 0; i < 6; i++)
		cout << s[i] << endl;
}