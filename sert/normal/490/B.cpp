#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;
const int N = 1e6 + 34;
const ll md = 1e9 + 7;

bool u[N][2];
int n2[N];
int x, y, n, f, s;

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        u[x][0] = true;
        u[y][1] = true;
        if (x == 0) s = y;
        n2[x] = y;
    }
    for (int i = 1; i < N; i++)
        if (u[i][0] && !u[i][1])
            f = i;

    while (true) {
        if (f == 0) break;
        cout << f << " ";
        f = n2[f];
        if (s == 0) break;
        cout << s << " ";
        s = n2[s];
    }

    //return 0;
}