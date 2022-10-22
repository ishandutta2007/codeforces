#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int N = 1013;

int a[N * 2][N * 2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, t;
    cin >> n >> t;

    a[N][N] = n;

    queue<pii> q;
    q.push({N, N});

    while(!q.empty()) {
        auto p = q.front();
        q.pop();

        int x = p.f, y = p.s;

        int s = a[x][y] / 4;
        a[x][y] %= 4;

//        cout << x << ' ' << y << ' ' << s << ' ' << a[x][y] << endl;

        a[x - 1][y] += s;
        a[x + 1][y] += s;
        a[x][y - 1] += s;
        a[x][y + 1] += s;

        if(a[x - 1][y] >= 4 && a[x - 1][y] - s < 4)
            q.push({x - 1, y});
        if(a[x + 1][y] >= 4 && a[x + 1][y] - s < 4)
            q.push({x + 1, y});
        if(a[x][y - 1] >= 4 && a[x][y - 1] - s < 4)
            q.push({x, y - 1});
        if(a[x][y + 1] >= 4 && a[x][y + 1] - s < 4)
            q.push({x, y + 1});
    }

    for(int i = 0; i < t; i++) {
        int x, y;
        cin >> x >> y;

        x += N;
        y += N;

//        cout << x << ' ' <<

        if(x < 0 || x >= N * 2 || y < 0 || y >= 2 * N)
            cout << 0;
        else
            cout << a[x][y];

        cout << '\n';
    }
}