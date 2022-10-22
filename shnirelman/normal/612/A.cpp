//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define x first
//#define y second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
//using matr

const int INF = 1e9 + 13;
const int N = 1e5 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;
const ld e = 1e-8;
const int LOGN = 20;

mt19937 rnd(time(0));


int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n, p, q;
    cin >> n >> p >> q;

    string s;
    cin >> s;

    for(int i = 0; i * p <= n; i++) {
        if((n - p * i) % q == 0) {
            cout << i + (n - p * i) / q << endl;

            for(int j = 0; j < i; j++) {
                for(int k = 0; k < p; k++)
                    cout << s[j * p + k];
                cout << endl;
            }

            for(int j = 0; j < (n - p * i) / q; j++) {
                for(int k = 0; k < q; k++)
                    cout << s[i * p + j * q + k];
                cout << endl;
            }
            return 0;
        }
    }

    cout << -1 << endl;
}