#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int query(int move) {
    cout << "next";
    for (int i = 0; i < 10; i++) {
        if (move & (1 << i))
            cout << " " << i;
    }
    cout << endl;

    int grps, tmp;
    cin >> grps;

    for (int i = 0; i < grps; i++)
        cin >> tmp;

    return grps;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int grps;

    grps = query(1 + 2);
    grps = query(1);

    while (grps > 2) {
        grps = query(1 + 2);
        grps = query(1);
    }

    while (grps != 1) {
        grps = query(0b1111111111);
    }

    cout << "done" << endl;

    return 0;
}