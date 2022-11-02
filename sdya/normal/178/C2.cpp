#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cstring>
#include <string>
#include <queue>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 210000;

int h, m, n;
vector < vector < int > > trees;
vector < vector < int > > elems;

void update(vector < int > &t, int position, int delta) {
	for (int i = position; i < t.size(); i |= (i + 1))
		t[i] += delta;
}

int get(vector < int > &t, int position) {
	int res = 0;
	for (int i = position; i >= 0; i = (i & (i + 1)) - 1) 
		res += t[i];
	return res;
}

int get(vector < int > &t, int l, int r) {
	return get(t, r) - get(t, l - 1);
}

map < int, int > M;

int tree_id[maxN], tree_position[maxN];
int used[maxN];

void precalc() {
	for (int i = 0; i < h; ++i) {
		if (!used[i]) {
			vector < int > cur;
			int v = i;
			while (!used[v]) {
				cur.push_back(v);
				used[v] = true;
				v = (v + m) % h;
			}
			trees.push_back(vector < int > (cur.size(), 0));
			for (int j = 0; j < cur.size(); ++j)
				tree_id[cur[j]] = trees.size() - 1, tree_position[cur[j]] = j;
			elems.push_back(cur);
		}
	}
}

long long res = 0;

void add_id(int x, int hash) {
	int t_id = tree_id[hash], t_pos = tree_position[hash];
	int l, r;
	if (get(trees[t_id], t_pos, trees[t_id].size() - 1) != trees[t_id].size() - t_pos) {
		l = t_pos, r = trees[t_id].size() - 1;
	} else {
		l = 0, r = t_pos - 1;
		res += (long long)(trees[t_id].size() - t_pos);
	}

	int old_l = l;
	while (r - l > 1) {
		int key = (l + r) / 2;
		if (get(trees[t_id], old_l, key) != key - old_l + 1) {
			r = key;
		} else {
			l = key;
		}
	}
	if (get(trees[t_id], old_l, l) != l - old_l + 1) {
		M[x] = elems[t_id][l];
		update(trees[t_id], l, +1);
		res += (long long)(l - old_l);
	} else {
		M[x] = elems[t_id][r];
		update(trees[t_id], r, +1);
		res += (long long)(r - old_l);
	}
}

void erase_id(int x) {
	int position = M[x];
	update(trees[tree_id[position]], tree_position[position], -1);
}

char code;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d%d", &h, &m, &n);
	precalc();

	for (int i = 0; i < n; ++i) {
		scanf(" %c", &code); 
		if (code == '+') {
			int x, y;
			scanf("%d%d", &x, &y);
			add_id(x, y);
		} else {
			int x;
			scanf("%d", &x);
			erase_id(x);
		}
	}

	cout << res << endl;

	return 0;
}