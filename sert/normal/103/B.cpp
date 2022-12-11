#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 4010;
const ll INF = 1e9;
const ll md = 1e9 + 7;
const ll o720 = 301388891;

int p[N];
int n, m;

int fnd(int v) {
    return (v == p[v] ? v : p[v] = fnd(p[v]));
}

void uniq(int v1, int v2) {
    p[fnd(v1)] = fnd(v2);
}

int v1, v2;

int main() {

    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    cin >> n >> m;
    if (n != m) {
        cout << "NO\n";
        return 0;
    }
    for (int i = 0; i < n; i++) p[i] = i;
    for (int i = 0; i < m; i++) {
        cin >> v1 >> v2;
        uniq(v1 - 1, v2 - 1);
    }
    for (int i = 0; i < n; i++)
        if (fnd(0) != fnd(i)) {
            cout << "NO\n";
            return 0;
        }
    cout << "FHTAGN!\n";
    return 0;
}