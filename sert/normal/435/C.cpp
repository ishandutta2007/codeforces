#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll md = 1e9 + 7;
typedef long double ld;
const int N = 1e3 + 34;
const ld EPS = 1e-4;

char c[N][N];
vector <int> a;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            c[i][j] = ' ';
    int n, x;
    cin >> n;
    a.push_back(0);
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (i % 2 == 0) {
            for (int j = 0; j < x; j++)
                a.push_back(a.back() + 1);
        } else {
            for (int j = 0; j < x; j++)
                a.push_back(a.back() - 1);
        }
    }
    int mx = *max_element(a.begin(), a.end());
    int nn = 0, h;
    for (int i = 1; i < a.size(); i++) {
        h = mx - max(a[i], a[i - 1]);
        nn = max(nn, h);
        c[h][i - 1] = (a[i] < a[i - 1] ? '\\' : '/');
    }
    for (int i = 0; i <= nn; i++) {
        for (int j = 0; j + 1 < a.size(); j++)
            printf("%c", c[i][j]);
        printf("\n");
    }


    return 0;
}