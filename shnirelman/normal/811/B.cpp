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
const int N = 1e4 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;

mt19937 rnd(36547);

/*

*/

int a[N];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    for(int i = 0;i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < q; i++) {
        int l, r, x;
        cin >> l >> r >> x;

        l--;
        x--;

        int cnt = 0;
        for(int j = l; j < r; j++)
            cnt += (a[j] < a[x]);

        cout << (cnt == x - l ? "Yes" : "No") << '\n';
    }
}