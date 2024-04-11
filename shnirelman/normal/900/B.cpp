//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 20000 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;
const ld e = 1e-8;

mt19937 rnd(time(0));

/*

*/

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    a %= b;

    set<int> st;
    int cur = 1;
    while(true) {
        if(st.count(a)) {
            cout << -1;
            return 0;
        }
        st.insert(a);

        a *= 10;
        int d = a / b;
        a %= b;
        if(d == c) {
            cout << cur;
            return 0;
        }

        cur++;
    }
}