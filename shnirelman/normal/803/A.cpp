//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
#define x first
#define y second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
//using matr

const int INF = 1e9 + 13;
const int N = 6000 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;
const ld e = 1e-8;
const int LOGN = 20;

mt19937 rnd(time(0));

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    if(n * n < k) {
        cout << -1 << endl;
        return 0;
    }

    vector<vector<int>> a(n, vector<int>(n, 0));

//    if(k == 0) {
//        for(auto x : a) {
//            for(auto y : x)
//                cout << y << ' ';
//            cout << endl;
//        }
//
//        return 0;
//    }

    for(int i = 0; i < n && k >= 1; i++) {
        a[i][i] = 1;
        k--;

        for(int j = i + 1; j < n && k >= 2; j++) {
            a[i][j] = 1;
            a[j][i] = 1;
            k -= 2;
        }
    }

    if(k > 0) {
        cout << -1 << endl;
    } else {
        for(auto x : a) {
            for(auto y : x)
                cout << y << ' ';
            cout << endl;
        }
    }
}