#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, d, h;
    cin >> n >> d >> h;
    if (d < h || d > 2 * h) {
        cout << -1 << endl;
        return 0;
    }
    if (d == 1 && h == 1) {
        if (n == 2) {
            cout << "1 2" << endl;
            return 0;
        } else {
            cout << -1 << endl;
            return 0;
        }
    }
    vector<pair<int, int>> edges;
    int cnt = 1;
    for (int i = 0; i < h; i++) {
        edges.push_back({i, i + 1});
        cnt++;
    }
    int last = cnt - 1;
    if (cnt > n) {
        cout << -1 << endl;
        return 0;
    }
    if (d == h) {
        while (cnt < n) {
            edges.push_back({last - 1, cnt++});
        }
        for (auto p : edges) {
            cout << p.first + 1 << " " << p.second + 1 << endl;
        }
        return 0;
    } else {
        edges.push_back({0, cnt++});
        int dd = h + 1;
        while (dd < d) {
            edges.push_back({cnt - 1, cnt});
            cnt++;
            dd++;
        }
        if (cnt > n) {
            cout << -1 << endl;
            return 0;
        }
        while (cnt < n) {
            edges.push_back({0, cnt++});
        }
        for (auto p : edges) {
            cout << p.first + 1 << " " << p.second + 1 << endl;
        }
        return 0;
    }
    
    return 0;
}