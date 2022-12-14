#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;
const int N = 1e6 + 34;
const ll md = 1e9 + 7;

ll n, m;
char a[500][500];
ll p[N];

ll fnd(ll x) {
    return (x == p[x] ? p[x] : p[x] = fnd(p[x]));
}

void uniq(int v1, int v2) {
    v1 = fnd(v1);
    v2 = fnd(v2);
    if (v1 == v2) {
        cout << "Yes";
        exit(0);
    }
    p[v1] = v2;
}

int main() {
	// freopen("a.in", "r", stdin);
	// freopen("a.out", "w", stdout);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    for (int i = 0; i < n * m; i++)
        p[i] = i;
    for (int i = 1; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] == a[i - 1][j])
                uniq(i * m + j, (i - 1) * m + j);
    for (int i = 0; i < n; i++)
        for (int j = 1; j < m; j++)
            if (a[i][j] == a[i][j - 1])
                uniq(i * m + j, i * m + j - 1);

    cout << "No";
    //return 0;
}