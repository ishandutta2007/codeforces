#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 17;

int res[N];

pair<int, int> ask(int l, int r) {
    cout << "? " << l + 1 << " " << r << endl;
    int x, f;
    cin >> x;
    if (x == -1) {
        exit(0);
    }
    cin >> f;
    return {x, f};
}

void go(int l, int r) {
    if (l >= r) {
        return;
    }
    auto a = ask(l, r);
    int mini = 1e9, maxi = -1e9;
    for (int i = 0; i < r - l; ++i) {
        if (i < a.second && r - l - a.second <= i) {
            mini = min(mini, l + i);
            maxi = max(maxi, l + i);
        }
    }
    if (mini == 1e9) {
        int mid = (l + r) / 2;
        go(l, mid);
        go(mid, r);
    } else {
        for (int i = mini; i <= maxi; ++i) {
            res[i] = a.first;
        }
        go(l, mini);
        go(maxi + 1, r);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    go(0, n);
    cout << "!";
    for (int i = 0; i < n; ++i) {
        cout << " " << res[i];
    }
    cout << endl;
    return 0;
}