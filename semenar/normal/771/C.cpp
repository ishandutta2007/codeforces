//#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	vector<vector<int>> graph(n);

	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	vector<int> seq;
	vector<bool> added(n);
	vector<int> parent(n);

	seq.push_back(0);
	added[0] = true;
	parent[0] = -1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < graph[seq[i]].size(); j++) {
			if (!added[graph[seq[i]][j]]) {
				parent[graph[seq[i]][j]] = seq[i];
				added[graph[seq[i]][j]] = true;
				seq.push_back(graph[seq[i]][j]);
			}
		}
	}

	reverse(seq.begin(), seq.end());

	vector<long long> dist_sum(n);
	vector<vector<int>> vert_num(n, vector<int>(k));
	vector<long long> subtree_len(n);

	for (int i = 0; i < n; i++) {
		int x = seq[i];
		subtree_len[x] = 1;
		vert_num[x][0] = 1;
		dist_sum[x] = 0;
		for (int j = 0; j < graph[x].size(); j++) {
			if (graph[x][j] != parent[x]) {
				int y = graph[x][j];
				subtree_len[x] += subtree_len[y];
				for (int l = 0; l < k; l++) {
					vert_num[x][(l + 1) % k] += vert_num[y][l];
				}
				dist_sum[x] += dist_sum[y] + subtree_len[y];
			}
		}
	}

	vector<long long> rev_dist_sum(n);
	vector<vector<int>> rev_vert_num(n, vector<int>(k));

	for (int i = n - 1; i >= 0; i--) {
		int x = seq[i];
		if (parent[x] != -1) {
			int y = parent[x];
			for (int l = 0; l < k; l++) {
				rev_vert_num[x][(l + 1) % k] += rev_vert_num[y][l] + vert_num[y][l] - vert_num[x][(l + k - 1) % k];
			}
			rev_dist_sum[x] = rev_dist_sum[y] + n - subtree_len[y] + dist_sum[y] + subtree_len[y] - 2 * subtree_len[x] - dist_sum[x];
		}
	}

	long long answer = 0;

	for (int i = 0; i < n; i++) {
		dist_sum[i] += rev_dist_sum[i];
		for (int j = 0; j < k; j++) {
			dist_sum[i] += (vert_num[i][j] + rev_vert_num[i][j]) * ((k - j) % k);
		}
		answer += dist_sum[i] / k;
	}

	cout << answer / 2 << endl;

	return 0;
}