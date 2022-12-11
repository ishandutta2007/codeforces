#include <iostream>
#include <cstdio>
#include <vector>
#include <set>

using namespace std;

typedef int ll;

const ll N = 2014;

vector <int> es[N];
int p[N], q;
int n, m, v1, v2, w;
int kol;

int main() {

    //freopen("a.in", "r", stdin);

    ///Test: #33, : 0 ., : 0 ,  : 0,   : 0, : CRASHED

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> v1 >> v2;
        v1--; v2--;
        es[v1].push_back(v2);
        es[v2].push_back(v1);
    }

    for (int i = 0; i < n; i++) {
        p[i] = n * 34 + 12345;
        if (es[i].size() == 1)
            q = p[i] = 1;
    }

    if (!q) {
        cout << "0\n";
        return 0;
    }

    for (int lw = 1; true; lw++) {
        q = 0;
        for (int i = 0; i < n; i++) {
            if (p[i] <= lw)
                continue;
            kol = 0;
            for (int j = 0; j < es[i].size(); j++) {
                w = es[i][j];
                if (p[w] > lw)
                    kol++;
            }
            if (kol == 1)
                q = p[i] = lw + 1;
        }
        if (!q) {
            cout << lw << "\n";
            return 0;
        }
    }

    return 0;
}