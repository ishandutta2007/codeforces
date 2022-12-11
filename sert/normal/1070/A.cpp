#include <bits/stdc++.h>
#define fr first
#define sc second
#define m_p make_pair
#define low_bo(a, x) lower_bound(a.begin(), a.end(), x) - a.begin()
#define up_bo(a, x) upper_bound(a.begin(), a.end(), x) - a.begin()

using namespace std;

typedef long long ll;

void setmin(int &x, int y){
	x = min(x, y);
}

void setmax(int &x, int y){
	x = max(x, y);
}

void setmin(ll &x, ll y){
	x = min(x, y);
}

void setmax(ll &x, ll y){
	x = max(x, y);
}

const ll llinf = 1e18 + 100;

const int maxn = 1e5 + 100, maxw = 1e6 + 100, inf = 1e9 + 100;

int dv, sum;

pair<pair<int, int>, int> q[501][5001];

int main() {
#ifdef MADE_BY_SERT
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#else
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin >> dv >> sum;
    for (int i = 0; i < dv; i++)
        for (int j = 0; j <= sum; j++)
            q[i][j].sc = -1;
    queue<pair<int, int> > g;
    g.push(m_p(0, 0));
    while (!g.empty()){
        int r = g.front().fr, s = g.front().sc;
        g.pop();
        for (int i = (r + s == 0); i < 10; i++){
            int v = (r * 10 + i) % dv, w = s + i;
            if (w <= sum && q[v][w].sc == -1)
                q[v][w] = m_p(m_p(r, s), i), g.push(m_p(v, w));
        }
    }
    if (q[0][sum].sc == -1){
        cout << -1;
        return 0;
    }
    string s;
    int x = 0, y = sum;
    while (q[x][y].sc != -1){
        s.push_back(q[x][y].sc + 48);
        int a = q[x][y].fr.fr, b = q[x][y].fr.sc;
        x = a;
        y = b;
    }
    reverse(s.begin(), s.end());
    cout << s;
}