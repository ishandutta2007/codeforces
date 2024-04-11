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
const int N = 2e5 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;
const ld e = 1e-8;
const int LOGN = 20;
const int K = 16 * 16;

mt19937 rnd(0);


int main() {
    int n;
    li k;
    cin >> n >> k;

    //k--;

    while(true) {
        if(k == (1ll << (n - 1))) {
            cout << n << endl;
            return 0;
        }

        if(k > (1ll << (n - 1)))
            k -= (1ll << (n - 1));

        n--;
    }
}