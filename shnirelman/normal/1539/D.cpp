#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 1e5 + 13;
const int LOGN = 20;
const int A = 27;

li a[N], b[N];
int p[N];

bool cmp(int i, int j) {
    return b[i] < b[j];
}

int main() {
//    int t = 1;
////    cin >> t;
//
//    while(t--)
//        solve();

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        p[i] = i;
    }

    sort(p, p + n, cmp);

    li res = 0;

    int l = 0, r = n - 1;
    li s = 0;
    while(r >= l) {

        if(s >= b[p[l]]) {
            res += a[p[l]];
            s += a[p[l]];
            l++;
        } else {
            li d = b[p[l]] - s;
            if(d > a[p[r]]) {
                res += a[p[r]] * 2;
                s += a[p[r]];
                r--;
            } else {
                res += d * 2;
                s += d;
                a[p[r]] -= d;
            }
        }
    }

    cout << res << endl;
}