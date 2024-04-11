#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 2e9 + 13;
const li INF64 = 2e18 + 13;
const int M = 998244353;
//const int A = 1e6 + 13;
const int N = 2e5 + 13;
const int B = 400;
const int LOGN = 20;

mt19937 rnd(7476);

//vector<int> A = {1, 0, 0, 2, 0, 1, 3, 0, 1, 0, 0, 2, 0, 1, 4, 0};
//vector<int> A = {0, 2, 1, 0};
//int cnt = 0;
//
//int query(int a, int b) {
//    cnt++;
//    if(A[a] == A[b])
//        return 0;
//    else if(A[a] > A[b])
//        return 1;
//    else
//        return 2;
//}

//
int query(int a, int b) {
    cout << "? " << a + 1 << ' ' << b + 1 << endl;
    int res;
    cin >> res;
    return res;
}


int solve(int n, int l) {
    if(n == 0) {
        return l;
    }

    if(n % 2 == 1) {
        int x = solve(n - 1, l);
        int y = solve(n - 1, l + (1 << n - 1));

        int res = query(x, y);
        if(res == 1)
            return x;
        else
            return y;
    }

    int a = solve(n - 2, l);
    int b = solve(n - 2, l + (1 << n - 2));
    int c = solve(n - 2, l + (1 << n - 1));
    int d = solve(n - 2, l + (1 << n - 1) + (1 << n - 2));

    /*if(rnd() % 2 == 0) {
        swap(c, d);
    }*/

    int r1 = query(a, c);
    //int r2 = query(b, c);

    if(r1 == 0) {
        int r2 = query(b, d);
        if(r2 == 1)
            return b;
        else
            return d;
    } else if(r1 == 1) {
        int r2 = query(a, d);
        if(r2 == 1)
            return a;
        else
            return d;
    } else {
        int r2 = query(b, c);
        if(r2 == 1)
            return b;
        else
            return c;
    }

//    if(r1 == 2 && r2 == 2)
//        return c;
//    else if(r1 == 1 && r2 == 2)
//        return a;
//    else if(r1 == 2 && r2 == 1)
//        return b;
//    else {
//        if(r2 == 1)
//            swap(a, b);
//
//        int r3 = query(a, d);
//
//        if(r3 == 1)
//            return a;
//        else
//            return d;
//    }
}

void solve() {
    int n;
    cin >> n;

    int res = solve(n, 0);
    cout << "! " << res + 1 << endl;
//    cout << cnt << ' ' << ((1 << n + 1) + 2) / 3 << endl;
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}