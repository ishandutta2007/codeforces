#include <bits/stdc++.h>
using namespace std;
typedef array<int, 2> pt;

pt cubes[55];
int grid[55][55], n, m;
vector<array<int, 4>> seq;

void gout() {
	for(int r = 1; r <= n; r++) {
		for(int c = 1; c <= n; c++) {
			cout << grid[r][c] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void move(int i, int dx, int dy) {
	int x = cubes[i][0], y = cubes[i][1];
	int nx = x + dx, ny = y + dy;
	if(grid[nx][ny] != 0 || nx < 1 || ny < 1 || nx > n || ny > n) {
		cout << "Invalid move idiot >:(\n";
		cout << i << " " << dx << " " << dy << endl;
		gout();
		exit(0);
	}
	grid[nx][ny] = i;
	cubes[i][0] = nx;
	cubes[i][1] = ny;
	grid[x][y] = 0;
	seq.push_back({x, y, nx, ny});
}

vector<array<int, 4>> solve() {
	// stage 1, condense columns
	int cur = 0;
	seq.clear();
	for(int c = 1; c <= n; c++) {
		int num = 0;
		for(int r = 1; r <= n; r++)
			num += (grid[r][c] > 0);
		if(num == 0)
			continue;
		//cout << "[" << cur + 1 << ", " << cur + num << "]\n";
		// cur + 1 to cur + num.
		int cr = n, xd = num;
		while(cr > 0) {
			if(grid[cr][c] == 0) {
				cr--;
				continue;
			}
			while(cr < cur + xd) {
				move(grid[cr][c], 1, 0);
				cr++;
			}
			cr--;
			xd--;
		}
		xd = 1, cr = 1;
		while(cr <= n) {
			if(grid[cr][c] == 0) {
				cr++;
				continue;
			}
			while(cr > cur + xd) {
				move(grid[cr][c], -1, 0);
				cr--;
			}
			cr++;
			xd++;
		}
		cur += num;
	}
	// gout();
	// stage 2 - move shit to center
	int targ = (n + 1)/2;
	for(int r = 1; r <= m; r++) {
		int p = 0, i;
		for(p = 1; p <= n; p++)
			if(grid[r][p]) {
				i = grid[r][p];
				break;
			}
		while(p < targ) {
			p++;
			move(i, 0, 1);
		}
		while(p > targ) {
			p--;
			move(i, 0, -1);
		}
	}
	// gout();

	// stage 3 - sort shit
	cur = 1;
	while(cur <= m) {
		if(grid[cur][targ] == cur) {
			cur++;
			continue;
		}

		int p;
		for(p = 1; p <= m; p++)
			if(grid[p][targ] == cur)
				break;

		move(cur, 0, 1);
		for(int i = p - 1; i >= cur; i--) {
			move(grid[i][targ], 1, 0);
			move(cur, -1, 0);
		}
		move(cur, 0, -1);
		cur++;
	}
	// gout();

	return seq;
}

int main() {
	cin >> n >> m;
	if(n == 1) {
		cout << "0\n";
		return 0;
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			grid[i][j] = 0;
	for(int i = 1; i <= m; i++) {
		cin >> cubes[i][0] >> cubes[i][1];
		grid[cubes[i][0]][cubes[i][1]] = i;
	}
	auto A = solve();
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			grid[i][j] = 0;
	for(int i = 1; i <= m; i++) {
		cin >> cubes[i][0] >> cubes[i][1];
		grid[cubes[i][0]][cubes[i][1]] = i;
	}
	auto B = solve();
	reverse(B.begin(), B.end());
	cout << A.size() + B.size() << '\n';
	for(auto m : A)
		cout << m[0] << " " << m[1] << " " << m[2] << " " << m[3] << '\n';

	for(auto m : B)
		cout << m[2] << " " << m[3] << " " << m[0] << " " << m[1] << '\n';
}