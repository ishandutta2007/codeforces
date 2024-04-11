#include <bits/stdc++.h>

#define f first
#define s second
#define x first
#define y second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 2e9 + 13;
const int M = 1e9 + 7;
const int N = 1e5 + 13;
const int K = N * 30;
const int LOG = 30;

mt19937 rnd(time(0));

pii operator - (pii a, pii b) {
    return pii(a.x - b.x, a.y - b.y);
}

li vect(pii a, pii b) {
    return a.x * 1ll * b.y - a.y * 1ll * b.x;
}

pii a[N];



bool is(int i, int j, int k) {
    return vect(a[i] - a[j], a[k] - a[j]) == 0;
}


int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i].f >> a[i].s;
    }

    if(n == 1) {
        cout << "YES" << endl;
        return 0;
    }

    for(int ind = 0; ind < 20; ind++) {
        int i = rnd() % n;
        int j = rnd() % n;

        if(i == j) {
            ind--;
            continue;
        }

        int i1 = -1, j1 = -1;
        bool res = true;
        for(int k = 0; k < n; k++) {
            if(is(i, j, k))
                continue;
            if(i1 == -1)
                i1 = k;
            else if(j1 == -1)
                j1 = k;
            else if(!is(i1, j1, k)) {
                res = false;
                break;
            }
        }

        if(res) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}