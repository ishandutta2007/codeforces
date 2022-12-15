#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const int N = 500 + 3;
const ll INF = 1e18;

int n;
ll c[N][N], p[N][N], ans[N][N];

void init(){
    for(int i = 1; i <= 2 * n; ++i)
        for(int j = 1; j <= 2 * n; ++j)
            p[i][j] = c[i][j] +  p[i][j - 1] + p[i - 1][j] - p[i - 1][j - 1];
}

ll query(int x1, int y1, int x2, int y2){
    return p[x2][y2] - p[x1 - 1][y2] - p[x2][y1 - 1] + p[x1 - 1][y1 - 1];
}

void solve(){
    cin >> n;
    for(int i = 1; i <= 2 * n; ++i)
        for(int j = 1; j <= 2 * n; ++j)
            cin >> c[i][j];

    init();

    for(int i = 1; i <= 2 * n; ++i)
        for(int j = 1; j <= 2 * n; ++j)
            ans[i][j] = INF;

    priority_queue<array<ll, 3>, vector<array<ll, 3>>, greater<array<ll, 3>>> pq;
    pq.push({0, 1, 1});
    ans[1][1] = 0;
    pq.push({0, 1, n});
    ans[1][n] = 0;
    pq.push({0, n, 1});
    ans[n][1] = 0;
    pq.push({0, n, n});
    ans[n][n] = 0;

    ll cost_down = 0;
    for(int i = n + 1; i <= 2 * n; ++i)
        for(int j = n + 1; j <= 2 * n; ++j){
            cost_down += c[i][j];
            c[i][j] = 0;
        }

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            c[i][j] = INF;

    while(!pq.empty()){
        auto [d, x, y] = pq.top();
        pq.pop();

        //cout << d << " " << x << " " << y << " d x y" << endl;

        if(x >= n + 1 && y >= n + 1){
            cout << d + cost_down << "\n";
            return;
        }
        if(ans[x][y] != d)
            continue;

        int nxt_x = (x == 2 * n) ? 1 : (x + 1);
        ll cand = d + c[nxt_x][y];
        if(cand < ans[nxt_x][y]){
            ans[nxt_x][y] = cand;
            pq.push({cand, nxt_x, y});
        }

        int nxt_y = (y == 2 * n) ? 1 : (y + 1);
        cand = d + c[x][nxt_y];
        if(cand < ans[x][nxt_y]){
            ans[x][nxt_y] = cand;
            pq.push({cand, x, nxt_y});
        }

        nxt_x = (x == 1) ? 2 * n : (x - 1);
        cand = d + c[nxt_x][y];
        if(cand < ans[nxt_x][y]){
            ans[nxt_x][y] = cand;
            pq.push({cand, nxt_x, y});
        }

        nxt_y = (y == 1) ? 2 * n : (y - 1);
        cand = d + c[x][nxt_y];
        if(cand < ans[x][nxt_y]){
            ans[x][nxt_y] = cand;
            pq.push({cand, x, nxt_y});
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--)
        solve();
}