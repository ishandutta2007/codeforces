#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

#define TRACE(x)
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int query(int x1, int y1, int x2, int y2) {
    cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    int res;
    cin >> res;
    return res;
}

void print(array<int, 4> arg) {
    for (int i = 0; i < 4; i++)
        cout << " " << arg[i];
}

void print(array<int, 4> r1, array<int, 4> r2) {
    cout << "!";
    print(r1);
    print(r2);
    cout << endl;
}

// only one rectangle inside
array<int, 4> solve(int r1, int c1, int r2, int c2) {
    TRACE(cout << "Solving in " << r1 << " " << c1 << " " << r2 << " " << c2 << endl;)
    // tighten r1
    int lo = r1+1, hi = r2;
    while (lo <= hi) {
        int mi = (lo + hi) / 2;
        int ct = query(mi, c1, r2, c2);
        if (ct == 1) {
            r1 = mi;
            lo = mi + 1;
        } else {
            hi = mi - 1;
        }
    }
    // tighten r2
    lo = r1, hi = r2-1;
    while (lo <= hi) {
        int mi = (lo + hi) / 2;
        int ct = query(r1, c1, mi, c2);
        if (ct == 1) {
            r2 = mi;
            hi = mi - 1;
        } else {
            lo = mi + 1;
        }
    }
    // tighten c1
    lo = c1+1, hi = c2;
    while (lo <= hi) {
        int mi = (lo + hi) / 2;
        int ct = query(r1, mi, r2, c2);
        if (ct == 1) {
            c1 = mi;
            lo = mi + 1;
        } else {
            hi = mi - 1;
        }
    }
    // tighten c2
    lo = c1, hi = c2-1;
    while (lo <= hi) {
        int mi = (lo + hi) / 2;
        int ct = query(r1, c1, r2, mi);
        if (ct == 1) {
            c2 = mi;
            hi = mi - 1;
        } else {
            lo = mi + 1;
        }
    }

    return { r1, c1, r2, c2 };
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;

    // try to find horizontal dividing line
    int lo = 1, hi = N-1;
    while (lo <= hi) {
        int mi = (lo + hi) / 2;

        int ct = query(1, 1, mi, N);
        int ct2 = query(mi + 1, 1, N, N);

        if (ct == 1 && ct2 == 1) {
            auto r1 = solve(1, 1, mi, N);
            auto r2 = solve(mi + 1, 1, N, N);
            print(r1, r2);
            return 0;
        } else if (ct == 0) {
            lo = mi + 1;
        } else {
            hi = mi - 1;
        }
    }

    // now try vertical
    lo = 1, hi = N-1;
    while (lo <= hi) {
        int mi = (lo + hi) / 2;

        int ct = query(1, 1, N, mi);
        int ct2 = query(1, mi + 1, N, N);

        if (ct == 1 && ct2 == 1) {
            auto r1 = solve(1, 1, N, mi);
            auto r2 = solve(1, mi + 1, N, N);
            print(r1, r2);
            return 0;
        } else if (ct == 0) {
            lo = mi + 1;
        } else {
            hi = mi - 1;
        }
    }

    assert(false);
}