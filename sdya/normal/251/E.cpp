#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 210000;
const long long P = 1000000007LL;
int n;
vector < int > g[maxN];
int s[maxN], used[maxN], d[maxN], nodes[maxN];

int next_node[maxN], length_to_the_node[maxN];

int is_node(int v) {
	return g[v].size() == 3;
}

void dfs(int v, int depth = 0) {
	used[v] = true;
	d[v] = depth;
	
	s[v] = 1;
	if (is_node(v)) {
		++nodes[v];
	}

	for (int i = 0; i < g[v].size(); ++i) {
		if (!used[g[v][i]]) {
			dfs(g[v][i], depth + 1);
			next_node[v] = next_node[g[v][i]];
			length_to_the_node[v] = length_to_the_node[g[v][i]] + 1;
			s[v] += s[g[v][i]];
			nodes[v] += nodes[g[v][i]];
		}
	}

	if (is_node(v)) {
		next_node[v] = v;
		length_to_the_node[v] = 1;
	}
}

long long ways[maxN];
vector < long long > double_ways[maxN];
vector < pair < int, int > > children[maxN];

void generate_sons(int v, int sons[]) {
	int counter = 0;
	for (int i = 0; i < g[v].size(); ++i) {
		if (d[v] + 1 == d[g[v][i]]) {
			sons[counter ++] = g[v][i];
		}
	}
}

int get_unique_son(int v) {
	for (int i = 0; i < g[v].size(); ++i) {
		if (d[v] + 1 == d[g[v][i]]) {
			return g[v][i];
		}
	}
}

void generate_node(int v, int &node, int &length) {
	node = next_node[v], length = length_to_the_node[v];
}

long long get_ways(int head, int up, int down) {
	for (int i = 0; i < double_ways[head].size(); ++i) {
		if (children[head][i] == make_pair(up, down)) {
			return double_ways[head][i];
		}
	}
	return 0;
}

void update_ways(int head, int up, int down, long long value, bool deletion = false) {
	for (int i = 0; i < double_ways[head].size(); ++i) {
		if (children[head][i] == make_pair(up, down)) {
			double_ways[head][i] += value;
			double_ways[head][i] %= P;
			if (deletion) {
				ways[head] -= value;
				ways[head] %= P;
				ways[head] = (ways[head] + P) % P;
			}
			return ;
		}
	}
	double_ways[head].push_back(value);
	children[head].push_back(make_pair(up, down));
	if (deletion) {
		ways[head] -= value;
		ways[head] %= P;
		ways[head] = (ways[head] + P) % P;
	}
}

void generate_ways(int head, int up, int down, bool deletion = false) {
	if ((s[up] + s[down]) % 2 != 0) {
		return ;
	}
	if (nodes[up] != 0 && nodes[down] != 0) {
		return ;
	}
	if (nodes[up] == 0 && nodes[down] == 0) {
		int first_chain = s[up], second_chain = s[down];
		if (first_chain < second_chain) {
			swap(first_chain, second_chain);
		}
		int value = max(1, (first_chain - second_chain) / 2);
		update_ways(head, up, down, value, deletion);
		return ;
	}

	if (nodes[up] != 0) {
		int node, length;
		generate_node(up, node, length);
		int sons[2];
		generate_sons(node, sons);

		for (int i = 0; i < 2; ++i, swap(sons[0], sons[1])) {
			if (nodes[sons[0]] == 0 && (s[sons[0]] + s[down]) <= length - 2 && (s[sons[0]] + s[down] + length) % 2 == 0) {
				update_ways(head, up, down, ways[sons[1]], deletion);
			}
			if (nodes[sons[0]] == 0 && (s[sons[0]] + s[down]) <= length && (s[sons[0]] + s[down] + length) % 2 == 0) {
				update_ways(head, up, down, ways[sons[1]], deletion);
			}
			if (is_node(sons[0])) {
				int grandsons[2];
				generate_sons(sons[0], grandsons);

				for (int j = 0; j < 2; ++j, swap(grandsons[0], grandsons[1])) {
					if (nodes[grandsons[0]] == 0 && s[grandsons[0]] + s[down] + 1 <= length && (s[grandsons[0]] + s[down] + 1 + length) % 2 == 0) {
						update_ways(head, up, down, get_ways(node, sons[1], grandsons[1]), deletion);
					}
				}
			} else {
				if (s[sons[0]] != 1) {
					int grandson = get_unique_son(sons[0]);
					if (s[down] <= length - 1 && (s[down] + length + 1) % 2 == 0) {
						update_ways(head, up, down, get_ways(node, sons[1], grandson), deletion);
					}
				}
			}
		}
	} else {
		int node, length;
		generate_node(down, node, length);
		int sons[2];
		generate_sons(node, sons);

		for (int i = 0; i < 2; ++i, swap(sons[0], sons[1])) {
			if (nodes[sons[0]] == 0 && (s[sons[0]] + s[up]) <= length - 2 && (s[sons[0]] + s[up] + length) % 2 == 0) {
				update_ways(head, up, down, ways[sons[1]], deletion);
			}
			if (nodes[sons[0]] == 0 && (s[sons[0]] + s[up]) <= length && (s[sons[0]] + s[up] + length) % 2 == 0) {
				update_ways(head, up, down, ways[sons[1]], deletion);
			}
			if (is_node(sons[0])) {
				int grandsons[2];
				generate_sons(sons[0], grandsons);

				for (int j = 0; j < 2; ++j, swap(grandsons[0], grandsons[1])) {
					if (nodes[grandsons[0]] == 0 && s[grandsons[0]] + s[up] + 1 <= length && (s[grandsons[0]] + s[up] + 1 + length) % 2 == 0) {
						update_ways(head, up, down, get_ways(node, sons[1], grandsons[1]), deletion);
					}
				}
			} else {
				if (s[sons[0]] != 1) {
					int grandson = get_unique_son(sons[0]);
					if (s[up] <= length - 1 && (s[up] + length + 1) % 2 == 0) {
						update_ways(head, up, down, get_ways(node, sons[1], grandson), deletion);
					}
				}
			}
		}
	}
}

void calculate_ways(int v) {
	for (int i = 0; i < g[v].size(); ++i) {
		if (d[v] + 1 == d[g[v][i]]) {
			calculate_ways(g[v][i]);
		}
	}

	vector < int > children;
	for (int i = 0; i < g[v].size(); ++i) {
		if (d[v] + 1 == d[g[v][i]]) {
			children.push_back(g[v][i]);
		}
	}

	if (children.size() == 1) {
		if (nodes[v] == 0) {
			ways[v] = s[v] / 2;
			return ;
		}

		int node, length, sons[2];
		generate_node(v, node, length);
		generate_sons(node, sons);

		for (int i = 0; i < 2; ++i, swap(sons[0], sons[1])) {
			if (nodes[sons[0]] == 0 && s[sons[0]] <= length - 2 && (s[sons[0]] + length) % 2 == 0) {
				ways[v] += ways[sons[1]];
				ways[v] %= P;
			}
			if (nodes[sons[0]] == 0 && s[sons[0]] <= length && (s[sons[0]] + length) % 2 == 0) {
				ways[v] += ways[sons[1]];
				ways[v] %= P;
			}

			if (is_node(sons[0])) {
				int grandsons[2];
				generate_sons(sons[0], grandsons);

				for (int j = 0; j < 2; ++j, swap(grandsons[0], grandsons[1])) {
					if (nodes[grandsons[0]] == 0 && s[grandsons[0]] <= length - 1 && (s[grandsons[0]] + length + 1) % 2 == 0) {
						ways[v] += get_ways(node, sons[1], grandsons[1]);
						ways[v] %= P;
					}
				}
			} else {
				if (s[sons[0]] != 1) {
					int grandson = get_unique_son(sons[0]);
					if ((length + 1) % 2 == 0) {
						ways[v] += get_ways(node, sons[1], grandson);
						ways[v] %= P;
					}
				}
			}
		}
	} else if (children.size() == 2) {
		int sons[2];
		generate_sons(v, sons);

		for (int i = 0; i < 2; ++i, swap(sons[0], sons[1])) {
			if (is_node(sons[0])) {
				int grandsons[2];
				generate_sons(sons[0], grandsons);

				for (int j = 0; j < 2; ++j, swap(grandsons[0], grandsons[1])) {
					generate_ways(v, sons[1], grandsons[1], true);
				}
				continue;
			}

			if (s[sons[0]] == 1) {
				ways[v] += ways[sons[1]];
				ways[v] %= P;
				continue;
			}

			int up = sons[1], down = get_unique_son(sons[0]);
			generate_ways(v, up, down);
		}

		for (int i = 0; i < double_ways[v].size(); ++i) {
			ways[v] += double_ways[v][i];
			ways[v] %= P;
		}
	}
}

long long get_sum(int v) {
	long long res = 0;
	for (int i = 0; i < double_ways[v].size(); ++i) {
		res += double_ways[v][i];
		res %= P;
	}
	return res;
}

void clear_ways(int v) {
	double_ways[v].clear();
	children[v].clear();
}

void solve(int root) {
	calculate_ways(root);
	int sons[3];
	generate_sons(root, sons);
	sort(sons, sons + 3);

	long long res = 0;
	do {
		int a = sons[0], b = sons[1], c = sons[2];
		if (!is_node(b)) {
			if (s[b] == 1) {
				if ((s[a] + s[b] + 1) % 2 == 0 && (s[c] + s[b] + 1) % 2 == 0) {
					res += ways[a] * ways[c];
					res %= P;
				}
			} else {
				for (int i = 0; i < 2; ++i, swap(a, c)) {
					if ((s[a] + s[b] + 1) % 2 == 0 && !is_node(a)) {
						int up = a, down = get_unique_son(b);
						clear_ways(root);
						generate_ways(root, up, down);
						res += get_sum(root) * ways[c];
						res %= P;
					}
				}
			}
		} else {
			int grandsons[2];
			generate_sons(b, grandsons);
			for (int i = 0; i < 2; ++i, swap(grandsons[0], grandsons[1])) {
				clear_ways(root);
				generate_ways(root, a, grandsons[0]);
				if ((s[a] + s[grandsons[0]]) % 2 != 0) {
					continue;
				}
				long long left = get_sum(root);

				clear_ways(root);
				if ((s[c] + s[grandsons[1]]) % 2 != 0) {
					continue;
				}
				generate_ways(root, c, grandsons[1]);
				long long right = get_sum(root);

				res += left * right;
				res %= P;
			}
		}
	} while (next_permutation(sons, sons + 3));

	res += res;
	res %= P;
	printf("%d\n", (int)(res));
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i < n + n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}

	int root = -1;
	for (int i = 1; i <= n + n; ++i) {
		if (g[i].size() > 3) {
			printf("0\n");
			return 0;
		}
		if (g[i].size() == 3) {
			root = i;
		}
	}

	if (root == -1) {
		if (n == 1) {
			printf("2\n");
		} else {
			long long m = n;
			long long res = (2LL * (m * m - m + 2)) % P;
			printf("%d\n", (int)(res));
		}
		return 0;
	}

	dfs(root);
	solve(root);

	return 0;
}