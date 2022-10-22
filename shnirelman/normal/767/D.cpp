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

mt19937 rnd(time(0));

bool is(vector<int> a, int k) {
    int cur = 0;
    for(int i = 0; i < a.size(); i++) {
        if(a[i] < cur) {
            return false;
        }
        if(i % k == k - 1)
            cur++;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> b(m);
    vector<pii> b1(m);
    for(int i = 0; i < m; i++) {
        cin >> b[i];
        b1[i] = {b[i], i};
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(b1.begin(), b1.end());

    if(!is(a, k)) {
        cout << -1 << endl;
        return 0;
    }

    int l = 0, r = m + 1;
    while(r - l > 1) {
        int mid = (l + r) / 2;

        vector<int> c(n + mid);
        int cur = 0;
        int i1 = 0, i2 = m - mid;
        for(int i = 0; i < c.size(); i++) {
            if(i1 < n && (i2 == m || a[i1] < b[i2])) {
                c[i] = a[i1++];
            } else {
                c[i] = b[i2++];
            }
        }

//        cout << l << ' ' << mid << ' ' << r<< endl;
//        for(auto x : c)
//            cout << x << ' ';
//        cout << endl << endl;

        if(is(c, k))
            l = mid;
        else
            r = mid;
    }

    cout << l << endl;
    for(int i = m - l; i < m; i++)
        cout << b1[i].s + 1 << ' ';
    cout << endl;
}