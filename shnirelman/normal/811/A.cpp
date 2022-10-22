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
const int N = 2e5 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;

mt19937 rnd(36547);

/*

*/


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    int l = 0, r = 1e9;
    while(r - l > 1) {
        int m = (l + r) / 2;

        if(m * 1ll * m > a)
            r = m;
        else
            l = m;
    }

    int resa = l;

    l = 0, r = 1e9;
    while(r - l > 1) {
        int m = (l + r) / 2;
        if(m * 1ll * (m + 1) > b)
            r = m;
        else
            l = m;
    }

    int resb = l;

    cout << (resa <= resb ? "Vladik" : "Valera") << endl;
}