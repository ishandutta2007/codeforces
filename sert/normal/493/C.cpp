#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;
const int N = 1e6 + 34;
const int M = 200;

ll s1, s2, b1, b2, bst = -2e9;
ll n, m, s, len;
pair <ll, ll> e[N];

void relax(ll r1, ll r2) {
    if (r1 - r2 >= bst) {
        bst = r1 - r2;
        b1 = r1;
        b2 = r2;
    }
}

int main() {
//     freopen("a.in", "r", stdin);
//     freopen("a.out", "w", stdout);

    bst = -bst * bst;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        e[len++] = make_pair(s, 0);
        s1 += 2;
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        e[len++] = make_pair(s, 1);
        s2 += 2;
    }

    relax(s1, s2);
    e[len++] = make_pair(-1, -1);
    sort(e, e + len);
    for (int i = len - 1; i > 0; i--) {
        if (e[i].second == 0) s1++;
        else s2++;
        if (e[i].first > e[i - 1].first)
            relax(s1, s2);
    }
    cout << b1 << ":" << b2 << "\n";
    //return 0;
}