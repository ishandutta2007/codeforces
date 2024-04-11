#include <string>
#include <fstream>;
#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

const long double malo = 1e-14;

bool u[101][101];
int n, k, cur, v1, v2;

vector <pair<int, int> > e;
vector <int> es[101];

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    srand(3431);
    cin >> k;
    n = 100;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            e.push_back(make_pair(i, j));
    while (true) {
        random_shuffle(e.begin(), e.end());
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                u[i][j] = false;
        for (int i = 0; i < n; i++)
            es[i].clear();
        cur = 0;
        for (int i = 0; i < e.size() && cur < k; i++) {
            v1 = e[i].first;
            v2 = e[i].second;
            u[v1][v2] = u[v2][v1] = true;

            for (int j = 0; j < es[v1].size(); j++)
                if (u[es[v1][j]][v2])
                    cur++;

            es[v1].push_back(v2);
            es[v2].push_back(v1);
        }

        if (cur == k) {
            cout << n << "\n";
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++)
                    cout << int(u[i][j]);
                cout << "\n";
            }
            return 0;
        }
    }
}