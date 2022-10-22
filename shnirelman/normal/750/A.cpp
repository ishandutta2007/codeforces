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
const int N = 1e6 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;
const ld e = 1e-8;
const int LOGN = 20;

mt19937 rnd(0);


int main() {

    int n, k;
    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        if((i + 2) * (i + 1) / 2 * 5 + k > 240) {
            cout << i << endl;
            return 0;
        }
    }

    cout << n<< endl;

}