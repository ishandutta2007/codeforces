#include <bits/stdc++.h>

const int INF = 1e9 + 7;
const int EPS = 1e-8;

#define ll long long
#define TASKNAME ""

using namespace std;

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
    #endif // MY
    int n, m;
    cin >> n >> m;
    bool fl = 0;
    if (n > m) {
        fl = 1;
        swap(n, m);
    }
    vector <vector <int> > data(n, vector <int> (m, 0));
    for (int i = 0; i < (fl ? m : n); i++) {
        for (int j = 0; j < (fl ? n : m); j++) {
            if (!fl) {
                cin >> data[i][j];
            } else {
                cin >> data[j][i];
            }
        }
    }
    vector <pair <int, int> > moves;
    for (int i = 0; i < n; i++) {
        int mink = INF;
        for (int j = 0; j < m; j++) {
            mink = min(mink, data[i][j]);
        }
        for (int j = 0; j < m; j++) {
            data[i][j] -= mink;
        }
        for (int k = 0; k < mink; k++) {
            moves.push_back({0, i});
        }
    }
    for (int j = 0; j < m; j++) {
        int cnt = data[0][j];
        for (int i = 0; i < n; i++) {
            if (data[i][j] != cnt) {
                cout << -1;
                return 0;
            }
        }
        for (int i = 0; i < cnt; i++) {
            moves.push_back({1, j});
        }
    }
    cout << moves.size() << endl;
    for (int i = 0; i < moves.size(); i++) {
        if ((!moves[i].first && !fl) || (moves[i].first && fl)) {
            cout << "row ";
        } else {
            cout << "col ";
        }
        cout << moves[i].second + 1 << endl;
    }
}