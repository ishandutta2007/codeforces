#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;
vector <vector <int> > a;
vector <vector <int> > lose, win, degree;
vector <vector <int> > used;
const int INF = 1e9 + 7;

int n;

void dfs(int v, int x) {
    used[v][x] = 1;
    int mink = INF;
    for (int u : a[x ^ 1]) {
        int next = (v - u + n) % n;
        if (!used[next][x ^ 1]) {
            if (lose[v][x]) {
                win[next][x ^ 1] = 1;
            } else if (--degree[next][x ^ 1] == 0) {
                lose[next][x ^ 1] = 1;
            } else {
                continue;
            }
            dfs(next, x ^ 1);
        }
    }
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //  freopen("output.txt", "w", stdout);
    #endif
    cin >> n;
    int k1;
    cin >> k1;
    a.resize(2);
    a[0].resize(k1, 0);
    for (int i = 0; i < k1; i++) {
        cin >> a[0][i];
    }
    int k2;
    cin >> k2;
    a[1].resize(k2, 0);
    for (int i = 0; i < k2; i++) {
        cin >> a[1][i];
    }
    lose.resize(n, vector <int> (2, 0));
    win.resize(n, vector <int> (2, 0));
    degree.resize(n, vector <int> (2, 0));
    used.resize(n, vector <int> (2, 0));
    for (int i = 0; i < n; i++) {
        degree[i][0] = k1;
        degree[i][1] = k2;
    }
    lose[0][0] = 1;
    lose[0][1] = 1;
    dfs(0, 0);
    dfs(0, 1);
    for (int i = 1; i < n; i++) {
        if (lose[i][0]) {
            cout << "Lose ";
        } else if (win[i][0]) {
            cout << "Win ";
        } else {
            cout << "Loop ";
        }
    }
    cout << endl;
    for (int i = 1; i < n; i++) {
        if (lose[i][1]) {
            cout << "Lose ";
        } else if (win[i][1]) {
            cout << "Win ";
        } else {
            cout << "Loop ";
        }
    }
}