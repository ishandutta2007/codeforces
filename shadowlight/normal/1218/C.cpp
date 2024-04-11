#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

struct trans{
	int x, y, d, t, e;
};

int n, m, k;

ll dp[505][505];
trans w[500007];

vector<int> kek[505][505];

bool in(int x, int y, int x1, int y1, int x2, int y2){
	return x >= x1 && x <= x2 && y >= y1 && y <= y2;
}

vector<pair<int, int> > ff[500007];

ll func[2][555][555];

vector<pair<int, int> > toto[2][505][505];

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;

	for (int i = 0; i < k; i++){
		cin >> w[i].x >> w[i].y >> w[i].d >> w[i].t >> w[i].e;
	}

	for (int i = 0; i < k; i++){
		int x = w[i].x;
		int y = w[i].y;
		int t = w[i].t;
		if (x + y >= t && (x + y - t) % 4 == 0) kek[x][y].pb(i), ff[i].pb({x, y});
		x = w[i].x + w[i].d;
		y = w[i].y - w[i].d;
		t = w[i].t + 1;
		if (x + y >= t && (x + y - t) % 4 == 0) kek[x][y].pb(i), ff[i].pb({x, y});
		x = w[i].x + w[i].d;
		y = w[i].y;
		t = w[i].t + 2;
		if (x + y >= t && (x + y - t) % 4 == 0) kek[x][y].pb(i), ff[i].pb({x, y});
		x = w[i].x;
		y = w[i].y + w[i].d;
		t = w[i].t + 3;
		if (x + y >= t && (x + y - t) % 4 == 0) kek[x][y].pb(i), ff[i].pb({x, y});
	}

	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			for (int v : kek[i][j]){
				int ma = -1;
				for (auto&& pl : ff[v]) if (pl.y == j && pl.x < i) ma = max(ma, pl.x);
				if (ma == -1){
					func[0][i][j] += w[v].e;
				} else {
					toto[0][i][j].pb({ma, w[v].e});
				}


				ma = -1;
				for (auto&& pl : ff[v]) if (pl.x == i && pl.y < j) ma = max(ma, pl.y);
				if (ma == -1){
					func[1][i][j] += w[v].e;
				} else {
					toto[1][i][j].pb({ma, w[v].e});
				}
			}
			sort(all(toto[0][i][j])); reverse(all(toto[0][i][j]));
			sort(all(toto[1][i][j])); reverse(all(toto[1][i][j]));
		}
	}

	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (i + j > 0) dp[i][j] = (ll)1e18;

	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
	
			//cout << i << ' ' << j << ' ' << dp[i][j] << ' ' << kek[i][j].size() << endl;

			ll add = dp[i][j];
			for (int to = i + 1; to < n; to++){

				while(toto[0][to][j].size() > 0 && toto[0][to][j].back().x < i){
					func[0][to][j] += toto[0][to][j].back().y;
					toto[0][to][j].pop_back();
				}
				add += func[0][to][j];

				//cout << to << ' ' << i << ' ' << j << ' ' << add << endl;
				dp[to][j] = min(dp[to][j], add);
			}


			add = dp[i][j];
			for (int to = j + 1; to < m; to++){

				while(toto[1][i][to].size() > 0 && toto[1][i][to].back().x < j){
					func[1][i][to] += toto[1][i][to].back().y;
					toto[1][i][to].pop_back();
				}
				add += func[1][i][to];

				//cout << to << ' ' << i << ' ' << j << ' ' << add << endl;
				dp[i][to] = min(dp[i][to], add);
			}
		}
	}

	cout << dp[n - 1][m - 1];
}