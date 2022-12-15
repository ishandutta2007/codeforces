#include <bits/stdc++.h>

using namespace std;

const int P = 17;
const int N = 1007;

int s[P];
string str[N];

struct castle{
	int x, y;
	int left;

	castle(int _x = 0, int _y = 0, int _left = 0){
		x = _x;
		y = _y;
		left = _left;
	}
};

void bfs(int n, int m, int p){
	queue<castle> q[P];

	for(int k = 1; k <= p; k++){
		char c = k + '0';

		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(str[i][j] == c){
					q[k].push(castle(i, j, s[k]));
				}
			}
		}
	}

	int cnt = 0;

	while(cnt < p){
		cnt = 0;
		for(int i = 1; i <= p; i++){
			if(q[i].empty()){
				cnt++;
				continue;
			}

			queue<castle> new_queue;

			while(!q[i].empty()){
				castle c = q[i].front();
				q[i].pop();

				//cout << c.x << " " << c.y << "\n";

				if(c.left == 0)
					continue;

				int pl = str[c.x][c.y] - '0';

				vector<pair<int, int> > adj = {{c.x - 1, c.y}, {c.x + 1, c.y}, {c.x, c.y - 1}, {c.x, c.y+1}};

				for(pair<int, int> coord: adj){
					if(coord.first < 0 || coord.first >= n || coord.second < 0 || coord.second >= m){
						continue;
					}

					if(str[coord.first][coord.second] == '.'){
						q[i].push(castle(coord.first, coord.second, c.left - 1));
						new_queue.push(castle(coord.first, coord.second, s[pl]));
						str[coord.first][coord.second ] = (char) pl + '0';
					}
				}
			}

			//cout << "\n";

			q[i] = new_queue;
		}
	}
}

int res[P];

int main (){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, p;

	cin >> n >> m >> p;

	for(int i = 1; i <= p; i++)
		cin >> s[i];

	for(int i = 0; i < n; i++)
		cin >> str[i];

	bfs(n, m, p);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(str[i][j] >= '1' && str[i][j] <= '9'){
				res[str[i][j] - '0']++;
			}
		}
	}

	for(int i = 1; i <= p; i++){
		cout << res[i] << " ";
	}

	cout << "\n";

	return 0;
}