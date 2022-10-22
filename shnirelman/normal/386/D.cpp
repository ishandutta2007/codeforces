#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int N = 73;
const int INF = 1e9;

int dp[N][N][N];
vector<int> p[N][N][N];
int n;

char g[N][N];

/*int calc(int a, int b, int c) {
    if(a > b)
        swap(a, b);
    if(b > c)
        swap(b, c);
    if(a > b)
        swap(a, b);

    cout << a << ' ' << b << ' ' << c << endl;

    if(dp[a][b][c] != -1)
        return dp[a][b][c];

    char ca = g[b][c], cb = g[a][c], cc = g[a][b];

    int a1 = -1, b1 = -1, c1 = -1, mx = INF;

    for(int i = 0; i < n; i++)
        if(i != a && i != b && i != c && g[a][i] == ca) {
            int res = calc(i, b, c);
            if(res < mx) {
                mx = res;
                a1 = i;
                b1 = b;
                c1 = c;
            }
        }

     for(int i = 0; i < n; i++)
        if(i != a && i != b && i != c && g[b][i] == cb) {
            int res = calc(a, i, c);
            if(res < mx) {
                mx = res;
                a1 = a;
                b1 = i;
                c1 = c;
            }
        }

     for(int i = 0; i < n; i++)
        if(i != a && i != b && i != c && g[c][i] == cc) {
            int res = calc(a, b, i);
            if(res < mx) {
                mx = res;
                a1 = a;
                b1 = b;
                c1 = i;
            }
        }

    p[a][b][c] = {a1, b1, c1};
    return dp[a][b][c] = mx + 1;
}*/

int main() {
    int a, b, c;
    cin >> n >> a >> b >> c;

    a--;
    b--;
    c--;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cin >> g[i][j];
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            for(int l = 0; l < n; l++)
                dp[i][j][l] = -1;

    dp[0][1][2] = 0;
    p[0][1][2] = {-1, -1, -1};

    queue<vector<int>> q;
    q.push({0, 1, 2});

    while(!q.empty()) {
        vector<int> x = q.front();
        q.pop();

        sort(x.begin(), x.end());

//        cout << x[0] << ' ' << x[1] << ' ' << x[2] << ' ' <<
//            dp[x[0]][x[1]][x[2]] << endl;

        for(int i = 0; i < 3; i++) {
            int a1 = x[i], b1 = x[(i + 1) % 3], c1 = x[(i + 2 ) % 3];
            char w = g[b1][c1];

//            cout << "\t" << a1 << ' ' << b1 << ' ' << c1 << endl;

            for(int j = 0; j < n; j++)
                if(g[a1][j] == w  && j != a1 && j != b1 && j != c1) {
                    vector<int> y = {j, b1, c1};
                    sort(y.begin(), y.end());

                    if(dp[y[0]][y[1]][y[2]] == -1) {
                        q.push(y);
                        dp[y[0]][y[1]][y[2]] = dp[x[0]][x[1]][x[2]] + 1;
                        p[y[0]][y[1]][y[2]] = {a1, b1, c1};
                    }
                }
        }
    }

    if(a > b)
        swap(a, b);
    if(b > c)
        swap(b, c);
    if(a > b)
        swap(a, b);

    if(dp[a][b][c] == -1) {
        cout << -1;
        return 0;
    }

    cout << dp[a][b][c] << endl;


    while(p[a][b][c][0] != -1) {
//        if(a > b)
//            swap(a, b);
//        if(b > c)
//            swap(b, c);
//        if(a > b)
//            swap(a, b);

//        cout << a << ' ' <<b << ' ' << c << endl;

        vector<int> nxt = p[a][b][c];
//        cout << nxt.size() << endl;

//        cout << "nxt " << nxt[0] << ' ' << nxt[1] << ' ' << nxt[2] << endl;

        set<int> s1 = {a, b, c};
        set<int> s2(nxt.begin(), nxt.end());

        int x, y;

        for(auto x1 : s1)
            if(s2.count(x1) == 0)
                x = x1;

        for(auto y1 : s2)
            if(s1.count(y1) == 0)
                y = y1;

        cout << x + 1 << ' ' << y + 1 << endl;
        sort(nxt.begin(), nxt.end());
        a = nxt[0], b = nxt[1], c = nxt[2];
//        cout << a << ' ' <<b << ' ' << c << endl;
//        cout << p[a][b][]
    }
}