//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define x first
//#define y second
#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pli = pair<li, li>;
//using matr

//const li INF = 2e18 + 13;
const int INF = 1e9 + 13;
const int N = 1e5 + 13;
const int M = 998244353;
const int B = 300;
//const int A = 26;
//const ld e = 1e-8;
const int LOGN = 20;
const int K = 170;

mt19937 rnd(0);

int sum(int a, int b) {
    a += b;

    return (a >= M ? a - M : a);
}

int dif(int a, int b) {
    return sum(a, M - b);
}

int mul(int a, int b) {
    return a * 1ll * b % M;
}

/*
3 5 0 0 5
1 3 1

*/


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    int cnt = 0;
    int x = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];

        if(a[i] % 2 != 0) {
            cnt++;
            x = i;
        }

    }

    if(n == 1) {
        cout << a[0] << endl;
        for(int i = 0; i < a[0]; i++)
            cout << 'a';
        cout << endl;
        return 0;
    }

    if(cnt > 1) {
        cout << 0 << endl;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < a[i]; j++)
                cout << char('a' + i);
        }
        cout << endl;
        return 0;
    }

//    if(n == 2) {
//        cout << 2 - cnt << endl;
//        for(int i = 0; i < n; i++) {
//            for(int j = 0; j < a[i]; j++)
//                cout << char('a' + i);
//        }
//        cout << endl;
//        return 0;
//    }

    if(cnt == 0) {
        int g = 0;
        for(auto x : a)
            g = __gcd(g, x / 2);

        cout << g * 2 << endl;
        for(int i = 0; i < g; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < a[j] / 2 / g; k++)
                    cout << char('a' + j);
            }

            for(int j = n - 1; j >= 0; j--) {
                for(int k = 0; k < a[j] / 2 / g; k++)
                    cout << char('a' + j);
            }
        }

        return 0;
    }

    int g = 0;
    for(auto x : a)
        g = __gcd(g, x);

    cout << g << endl;
    for(int i = 0; i < g; i++) {
        for(int j = 0; j < n; j++) if(j != x) {
            for(int k = 0; k < a[j] / 2 / g; k++)
                cout << char('a' + j);
        }

        for(int k = 0; k < a[x] / g; k++)
            cout << char('a' + x);

        for(int j = n - 1; j >= 0; j--) if(j != x) {
            for(int k = 0; k < a[j] / 2 / g; k++)
                cout << char('a' + j);
        }
    }



//    cout << 1 << endl;
//    for(int i = 0; i < n; i++) {
//        if(i != x) {
//           for(int j = 0; j < a[i] / 2; j++)
//                cout << char('a' + i);
//        }
//    }
//
//    for(int j = 0; j < a[x]; j++)
//        cout << char('a' + x);
//
//    for(int i = n - 1; i >= 0; i--) {
//        if(i != x) {
//           for(int j = 0; j < a[i] / 2; j++)
//                cout << char('a' + i);
//        }
//    }
}