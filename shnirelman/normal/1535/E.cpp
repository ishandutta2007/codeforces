#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int N = 3e5 + 13;
const int LOGN = 20;

int a[N], c[N];
int p[N][LOGN];

/*
*/

void add(int v, int pr, int a1, int c1) {
    a[v] = a1;
    c[v] = c1;


    p[v][0] = pr;
    for(int i = 1; i < LOGN; i++)
        p[v][i] = p[p[v][i - 1]][i - 1];
}

void get(int v, int x) {
    int y = 0;
    li res = 0;

    int u = v;
    while(true) {

        for(int i = i = LOGN - 1; i >= 0; i--) {
            if(a[p[v][i]] > 0)
                v = p[v][i];
        }

//        cout <<"get " << u << ' ' << v << ' ' << a[v] << ' ' << c[v] << endl;

        if(a[v] == 0)
            break;

        if(a[v] < x - y) {
            y += a[v];
            res += a[v] * 1ll * c[v];
            a[v] = 0;
        } else {
            res += (x - y) * 1ll * c[v];
            a[v] -= x - y;
            y = x;
            break;
        }
        v = u;
    }

    cout << y << ' ' << res << endl;

}

int main() {
    int q;
    cin >> q >> a[0] >> c[0];

    add(0, 0, a[0], c[0]);

    for(int i = 0; i < q; i++) {
        int t;
        cin >> t;

        if(t == 1) {
            int pr, a1, c1;
            cin >> pr >> a1 >> c1;

            add(i + 1, pr, a1, c1);
        } else {
            int v, x;
            cin >> v >> x;

            get(v, x);
        }
    }
}