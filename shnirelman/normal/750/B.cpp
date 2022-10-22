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

    int n;
    cin >> n;

    bool ans = true;
    int cur = 0;
    for(int i = 0; i < n; i++) {
        int x;
        string t;
        cin >> x >> t;

        if(t[0] == 'W' || t[0] == 'E') {
            ans &= (cur != 0 && cur != 20000);
        } else if(t[0] == 'S') {
            cur += x;
            ans &= (cur <= 20000);
        } else {
            cur -= x;
            ans &= (cur >= 0);
        }
    }

    cout << (ans && cur == 0 ? "YES" : "NO") << endl;
}