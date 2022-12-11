#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
const ld EPS = 1e-10;
const ld INF = (int)1e9 + 34;
const int N = (int)1e6 + 34;

void ret(int x) {
    cout << x;
    exit(0);
}

int n, k;
int a[N];
int b[N], len;
bool u[N];

int main() {
    /**freopen("walk.in", "w", stdout);
    int m = 300000;
    cout << m << " 395000\n";
    for (int i = 0; i < m; i++)
        cout << 799998 - i << " ";
    return 0;*/
    //freopen("walk.in", "r", stdin);
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    srand(3431);
    sort(a, a + n);

    a[n] = 100000000;
    int lst = a[0];
    b[len++] = a[0];
    for (int i = 1; i < n; i++)
        if (a[i + 1] - lst >= k) {
            b[len++] = lst = a[i];
        }

    int mn = a[0];
    for (int i = 0; i < n; i++)
        mn = min(mn, a[i]);

    vector <int> v;
    for (int i = 0; i < 30; i++)
        v.push_back(a[abs((rand() << 16) ^ rand()) % n]);
    for (int i = 1; i <= 1000000; i++)
        for (int j = 0; !u[i] && j < (int)v.size(); j++)
            if (v[j] % i > k)
                u[i] = true;


    int l1 = -1;
    int pr;
    bool fail;
    for (int d = mn; d >= 0; d--) {
        if (u[d])
            continue;
        fail = false;
        for (int i = 0; !fail && i < len; i++)
            if (b[i] % d > k)
                fail = true;
        if (!fail) {
            pr = d;
            break;
        }
        l1 = d;
    }
    for (int d = pr; d >= 0; d--) {
        if (u[d])
            continue;
        fail = false;
        for (int i = n - 1; !fail && i >= 0; i--)
            if (a[i] % d > k)
                fail = true;
        if (!fail) {
            pr = d;
            break;
        }
        l1 = d;
    }
    cout << pr;

    return 0;
}