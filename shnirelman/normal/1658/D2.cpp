#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
//const int M = 1e9 + 7;
const int M = 998244353;
const int N = 2e5 + 13;
const int LOGN = 30;

/*
1
4 7
4 7 6 5

1
3 4
7 0
*/

bool check(int l, int r, vector<int> a, int x) {
    int n = r - l + 1;
    vector<int> b(n);
    for(int i = 0; i < n; i++) {
        b[i] = (a[i] ^ x);
    }

    set<int> st(b.begin(), b.end());

//    cout << "check  res : ";
//    for(int y : st)
//        cout << y << ' ';
//    cout << endl;
//    cout << b.size() << ' ' << n << "  " << *b.begin() << ' ' << l << "   " << *b.rbegin() << ' ' << r << endl;

    return (b.size() == n && *st.begin() == l && *st.rbegin() == r);
}

int get(int l, int r, vector<int> a) {
    int n = r - l + 1;

    int k = 17;

    int x = 0;

    for(int i = k; i >= 0; i--) {
        vector<int> cnt(2, 0);
        for(int j = 0; j < n; j++) {
            cnt[(a[j] >> i) & 1]++;
        }

        if(cnt[1] > cnt[0])
            x |= (1 << i);
    }

//    cout << "get " << l << ' ' << r << " a : ";
//    for(int y : a)
//        cout << y << ' ';
//    cout << endl;
//    cout << "x = " << x << endl;
//    cout << "check " << check(l, r, a, x) << endl;

    if(check(l, r, a, x))
        return x;
    else
        return -1;
}

void out(string name, vector<int> a) {
    cout << name << " : ";
    for(int x : a)
        cout << x << ' ';
    cout << endl;
}

void solve() {
    int l, r;
    cin >> l >> r;

    int n = r - l + 1;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if(l == r) {
        cout << (l ^ a[0]) << endl;
        return;
    }

    int k = 17;

    int fir = -1;
    for(int i = k - 1; i >= 0; i--) {
        vector<int> cnt(2, 0);
        for(int j = 0; j < n; j++) {
            cnt[(a[j] >> i) & 1]++;
        }

        if(cnt[0] && cnt[1]) {
            fir = i;
            break;
        }
    }

    int x = ((a[0] >> fir + 1) ^ (l >> fir + 1)) << fir + 1;

//    cout << "x = " << x << endl;

    vector<int> b(n);
    for(int i = 0; i < n; i++) {
//        b[i] = (a[i] & (1 << fir + 1) - 1);
        b[i] = (a[i] & (1 << fir) - 1);
    }

//    cout << "fir = " << fir << " x = " << x << " b : ";
//    for(int i = 0; i < n; i++) {
//        cout << b[i] << ' ';
//    }
//    cout << endl;


    vector<int> b1, b2;
    for(int i = 0; i < n; i++) {
        if(a[i] & (1 << fir)) {
            b1.push_back(b[i]);
        } else {
            b2.push_back(b[i]);
        }
    }
//
//    out("b1", b1);
//    out("b2", b2);

//    if(false)
    {
        vector<int> c1 = b1, c2 = b2;
        for(int i = 0; i < c1.size(); i++) {
//            c1[i] ^= (1 << fir + 1) - 1;
            c1[i] ^= (1 << fir) - 1;
        }

//        out("c1", c1);
//        out("c2", c2);

        int x1 = get(0, c1.size() - 1, c1);
//        cout << "x1 = " << x1 << " ; xor " << ((1 << fir + 1) - 1) << " res = " << (x1 ^ ((1 << fir + 1) - 1)) << endl;
//        cout << "sdgfd" << endl;
        int x2 = get(0, c2.size() - 1, c2);
//        cout << "x2 = " << x2 << endl;

        if(x2 != -1 && x1 != -1) {
//            x1 ^= ((1 << fir + 1) - 1);
//            x1 ^= ((1 << fir) - 1);
            int y = (x | x1 | x2 | (1 << fir));
//            int y = (x | x1 | x2);

//            cout << "x1 = " << x1 << " x2 = " << x2 << " y = " << y << endl;

            if(check(l, r, a, y)) {
                cout << y << endl;
                return;
            }
        }


    }
//    return;
    {
        vector<int> c1 = b1, c2 = b2;
        for(int i = 0; i < c2.size(); i++) {
            c2[i] ^= (1 << fir) - 1;
        }

//        out("c1", c1);
//        out("c2", c2);

        int x1 = get(0, c1.size() - 1, c1);
        int x2 = get(0, c2.size() - 1, c2);

        if(x1 != -1 && x2 != -1) {
//            x2 ^= ((1 << fir) - 1);
//            int y = (x | x1 | x2) ^ (1 << fir);
            int y = (x | x1 | x2);
//cout << "x1 = " << x1 << " x2 = " << x2 << " y = " << y << endl;
            if(check(l, r, a, y)) {
                cout << y << endl;
                return;
            }
        }

    }


    cout << "isfasjbgsn" << endl;
//    cout << "res : ";
//    for(int y : a)
//        cout << (x ^ y) << ' ';
//    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}