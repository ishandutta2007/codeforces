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

    int n;
    cin >> n;

    int c0 = 0, c1 = 0;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        if(x < 0)
            c0++;
        else
            c1++;
    }

    cout << (min(c0, c1) <= 1 ? "Yes" : "No") << endl;
}