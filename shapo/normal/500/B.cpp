#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector< vector< int > > a, g;
vector< int > p;
int n;

int
main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    a.resize(n);
    p.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    for (int i = 0; i < n; ++i) {
        a[i].resize(n);
        for (int j = 0; j < n; ++j) {
            char c;
            cin >> c;
            a[i][j] = c - '0';
        }
    }
    g.assign(n, vector< int >(n, 0));
    for (int i = 0; i < n; ++i) {
        vector< int > qused(n, 0);
        vector< int > q(n, 0);
        int qh = 0, qt = 0;
        q[qt++] = i;
        qused[i] = true;
        while (qh < qt) {
            int cur = q[qh++];
            g[i][cur] = 1;
            for (int w = 0; w < n; ++w) {
                if (a[cur][w] && !qused[w]) {
                    qused[w] = true;
                    q[qt++] = w;
                }
            }
        }
    }
    vector< int > used(n, 0);
    for (int i = 0; i < n; ++i) {
        int ind = -1;
        for (int j = 0; j < n; ++j) {
            if (!used[j] && (ind == -1 || p[j] < p[ind])) {
                ind = j;
            }
        }
        int jnd = 0;
        while (used[jnd] || !g[jnd][ind]) {
            ++jnd;
        }
        swap(p[jnd], p[ind]);
        used[jnd] = true;
    }
    for (int i = 0; i < n; ++i) {
        cout << p[i] << ' ';
    }
    cout << '\n';
    return 0;
}