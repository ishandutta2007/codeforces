#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <iomanip>

using namespace std;

long long gcd(long long a, long long b) {
	return (a < b) ? gcd(b, a) : (b == 0 ? a : gcd(b, a % b));
}

bool make_path(int n, vector<pair<pair<int, int>, pair<int, int>>> &actions, vector<pair<int, int>> &cubes, int cube, pair<int, int> goal) {
	vector<bool> blockers(n * n, false);
	for (auto elem : cubes) {
		blockers[elem.first * n + elem.second] = true;
	}

	vector<vector<int>> graph(n * n);
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			if (!blockers[x * n + y]) {
				if (x > 0) graph[x * n + y].push_back((x - 1) * n + y);
				if (x < n - 1) graph[x * n + y].push_back((x + 1) * n + y);
				if (y > 0) graph[x * n + y].push_back(x * n + (y - 1));
				if (y < n - 1) graph[x * n + y].push_back(x * n + (y + 1));
			}
		}
	}

	vector<int> queue(1, goal.first * n + goal.second);
	vector<int> pr(n * n, -1);
	pr[queue[0]] = -2;
	int start = 0;

	while (start < queue.size()) {
		int x = queue[start];
		start++;

		for (auto v : graph[x]) {
			if (pr[v] == -1) {
				pr[v] = x;
				queue.push_back(v);
			}
		}
	}

	if (pr[cubes[cube].first * n + cubes[cube].second] == -1) {
		return false;
	}
	else {
		int pos = cubes[cube].first * n + cubes[cube].second;
		while (pr[pos] >= 0) {
			actions.push_back(make_pair(make_pair(pos / n, pos % n), make_pair(pr[pos] / n, pr[pos] % n)));
			pos = pr[pos];
		}
		cubes[cube] = goal;
		return true;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	/*int m, n;
	cin >> n >> m;

	vector<pair<int, int>> start_pos(m);
	for (int i = 0; i < m; i++) {
		cin >> start_pos[i].first >> start_pos[i].second;
		start_pos[i].first--;
		start_pos[i].second--;
	}

	vector<pair<int, int>> end_pos(m);
	for (int i = 0; i < m; i++) {
		cin >> end_pos[i].first >> end_pos[i].second;
		end_pos[i].first--;
		end_pos[i].second--;
	}

	if (n == 1) {
		cout << 0 << endl;
		return 0;
	}

	vector<pair<pair<int, int>, pair<int, int>>> actions;

	vector<pair<pair<int, int>, int>> cubes;

	for (int i = 0; i < m; i++) {
		cubes.push_back(make_pair(start_pos[i], i));
	}

	sort(cubes.begin(), cubes.end());

	for (int i = 0; i < m; i++) {
		make_path(n, actions, start_pos, cubes[i].second, make_pair(0, i));
	}

	vector<int> end_pos_by_col(n, 0);
	for (auto elem : end_pos) end_pos_by_col[elem.first]++;

	int lower_boundary = n - 1;
	while (end_pos_by_col[lower_boundary] > 1) lower_boundary--;

	if (n > 4) {
		lower_boundary = 1;
		while (end_pos_by_col[lower_boundary] > 1) lower_boundary++;
	}

	for (int col = n - 1; col > lower_boundary; col--) {
		for (int i = 0; i < m; i++) {
			if (end_pos[i].first == col) {
				make_path(n, actions, start_pos, i, end_pos[i]);
			}
		}
	}

	for (int col = 0; col < lower_boundary; col++) {
		for (int i = 0; i < m; i++) {
			if (start_pos[i].first == col) {
				make_path(n, actions, start_pos, i, make_pair(start_pos[i].first + 1, start_pos[i].second));
			}
		}
		for (int i = 0; i < m; i++) {
			if (end_pos[i].first == col) {
				make_path(n, actions, start_pos, i, end_pos[i]);
			}
		}
	}

	for (int i = 0; i < m; i++) {
		if (end_pos[i].first == lower_boundary) {
			make_path(n, actions, start_pos, i, end_pos[i]);
		}
	}

	cout << actions.size() << endl;

	for (auto action : actions) {
		cout << action.first.first + 1 << ' ' << action.first.second + 1 << ' ' << action.second.first + 1 << ' ' << action.second.second + 1 << endl;
	}*/

	int n;

	cin >> n;

	int start_x = 0, start_y = 0, end_x = n - 1, end_y = n - 1;

	string path_from_start;
	while (start_x + start_y < n - 1) {
		cout << "? " << start_x + 1 + 1 << ' ' << start_y + 1 << ' ' << n << ' ' << n << endl;
		cout.flush();
		string ans;
		cin >> ans;
		if (ans == "YES") {
			start_x += 1;
			path_from_start.push_back('D');
		}
		else {
			start_y += 1;
			path_from_start.push_back('R');
		}
	}

	string path_to_end;
	while (end_x + end_y > n - 1) {
		cout << "? " << 1 << ' ' << 1 << ' ' << end_x + 1 << ' ' << end_y + 1 - 1 << endl;
		cout.flush();
		string ans;
		cin >> ans;
		if (ans == "YES") {
			end_y -= 1;
			path_to_end.push_back('R');
		}
		else {
			end_x -= 1;
			path_to_end.push_back('D');
		}
	}

	reverse(path_to_end.begin(), path_to_end.end());

	cout << "! " << path_from_start << path_to_end << endl;
	cout.flush();

	return 0;
}