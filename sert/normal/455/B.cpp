#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 34;
typedef long double ld;

int d[N][30];
bool w[N][2];
int sz = 1, v;

void add(string s) {
    v = 0;
    for (char ch: s) {
        if (!d[v][ch - 'a']) {
            d[v][ch - 'a'] = sz++;
        }
        v = d[v][ch - 'a'];
    }
}

int main() {
    //freopen("a.in", "r", stdin);
    int n, k;
    string s;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> s;
        add(s);
    }
    bool sn;

    for (int i = sz - 1; i >= 0; i--) {
        for (int j = 0; j < 2; j++) {
            sn = false;
            for (int k = 0; k < 30; k++) {
                if (d[i][k]) sn = true;
                if (d[i][k] && !w[d[i][k]][j])
                    w[i][j] = true;
            }
            if (j == 1 && !sn)
                w[i][j] = true;
        }
    }

    if (w[0][1]) {
        if (w[0][0])
            cout << "First\n";
        else
            cout << "Second\n";
        return 0;
    }

    if (w[0][0]) {
        if (k % 2)
            cout << "First\n";
        else
            cout << "Second\n";
    } else
        cout << "Second\n";


    return 0;
}