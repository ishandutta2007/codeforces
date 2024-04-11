#include <iostream>
#include <vector>
#include <string>
#include<queue>

using namespace std;


int main()
{
	int n, m, k, fx, fy, cx, cy, nx, ny, av = 0;
	cin >> n >> m >> k;
	if (k % 2) {
		cout << "IMPOSSIBLE";
		return 0;
	}
	vector<string>a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		for (int j = 0; j < m; j++)
			if (a[i][j] == 'X') {
				fx = i; fy = j;
			}
	}
	queue<pair<int, int> >q;
	vector<vector<int> >dist(n, vector<int>(m, 10000000));
	vector<vector<bool> >used(n, vector<bool>(m, 0));
	dist[fx][fy] = 0;
	q.push(make_pair(fx, fy));
	const int tr[4][2] = { {1,0},{0,-1},{0,1},{-1,0} };
	const char ch[] = "DLRU";
	while (!q.empty()) {
		cx = q.front().first;
		cy = q.front().second;
		//cout << cx<<' ' << cy << endl;
		q.pop();
		if (used[cx][cy]) continue;
		av++;
		used[cx][cy] = 1;
		for (int i = 0; i < 4; i++) {
			nx = cx + tr[i][0]; ny = cy + tr[i][1];
			//cout << ' ' << nx << ' ' << ny << endl;
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny]!='*' && dist[nx][ny] > 1 + dist[cx][cy]) {
				q.push(make_pair(nx, ny));
				dist[nx][ny] = dist[cx][cy] + 1;
			}
		}
	}
	if(av<2) {
		cout << "IMPOSSIBLE";
		return 0;
	}
	int cm = 0;
	cx = fx; cy = fy;
	for (int cm = 0; cm < k; cm++) {
		for (int i = 0; i < 4; i++) {
			nx = cx + tr[i][0]; ny = cy + tr[i][1];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] != '*' && cm + dist[nx][ny] < k) {
				cx = nx; cy = ny;
				cout << ch[i];
				break;
			}
		}
	}
	return 0;
}