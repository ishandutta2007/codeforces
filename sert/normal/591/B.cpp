#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
const int N = 1e6 + 34;

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

queue <int> q;
int d[N][3];
vector <int> es[N];
char c[1234][1234];
int n, m, x, y;
bool u[N];
int dd[3];
char ch;
int ans = 10000500, mx;

void dij(int r) {
    while (!q.empty()) q.pop();
    dd[0] = dd[1] = dd[2] = 10000500;
    for (int i = 0; i < n * m + 5; i++)
        d[i][r] = 10000500;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (c[i][j] - '1' == r) {
                q.push(i * m + j);
                d[i * m + j][r] = 0;
            }
    int v;
    dd[r] = 0;
    while (!q.empty()) {
        v = q.front();
        y = v / m;
        x = v % m;
        q.pop();
        for (int i = 0; i < 4; i++) {
            if (x + dx[i] < 0 || y + dy[i] < 0 || x + dx[i] >= m || y + dy[i] >= n)
                continue;
            v = (y + dy[i]) * m + x + dx[i];
            if (d[v][r] != 10000500 || u[v])
                continue;
            d[v][r] = d[y * m + x][r] + 1;
            ch = c[y + dy[i]][x + dx[i]];
            if (ch != '.')
                dd[ch - '1'] = min(dd[ch - '1'], d[v][r] + 1);
            q.push(v);
        }
    }
    ans = min(ans, dd[0] + dd[1] + dd[2] - 2);
}

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    int a[26], b[26];
    string s;
    char v1, v2;
    cin >> n >> m;
    cin >> s;
    for (int i = 0; i < 26; i++)
        a[i] = i;
    while (m--) {
        cin >> v1 >> v2;
        v1 -= 'a';
        v2 -= 'a';
        swap(a[v1], a[v2]);
    }
    for (int i = 0; i < 26; i++)
        b[a[i]] = i;

    for (int i = 0; i < n; i++)
        s[i] = char(b[s[i] - 'a'] + 'a');
    cout << s;

    return 0;
}