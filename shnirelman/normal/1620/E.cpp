#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 2e18 + 13;
const int N = 5e5 + 113;
const int K = 1e5 + 113;
const int M = 1e9 + 7;
const int A = 26;

/*

*/

int p[N], sz[N];

int getp(int x) {
    return (x == p[x] ? x : p[x] = getp(p[x]));
}

void unite(int x, int y) {
    x = getp(x);
    y = getp(y);

    if(x == y)
        return;

    if(sz[x] < sz[y])
        swap(x, y);

    p[y] = x;
    sz[x] += sz[y];
}

int lst[N];

int a[N];

/*
4
1 3
1 1
2 1 2
1 2

3
1 1
2 1 2
1 2

2
1 2
1 2
*/

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;

    for(int i = 0; i < N; i++) {
        lst[i] = -1;
        p[i] = i;
        sz[i] = 1;
    }

    int sz = 0;
    for(int i = 0; i < q; i++) {
        int t;
        cin >> t;

        if(t == 1) {
            int x;
            cin >> x;



            if(lst[x] != -1) {
                unite(sz, lst[x]);

            } else {

            }

            lst[x] = sz;

            sz++;
        } else {
            int x, y;
            cin >> x >> y;

            if(lst[x] != -1 && x != y) {
                if(lst[y] != -1) {
                    unite(lst[x], lst[y]);
                    lst[y] = max(lst[y], lst[x]);
                } else {
                    lst[y] = lst[x];
//                    cout << "set lst[ " << y << " ] = " << lst[y] << endl;
                }
                lst[x] = -1;
            }
        }
    }

    for(int i = 0; i < N; i++) {
        if(lst[i] != -1) {
            a[getp(lst[i])] = i;
        }
    }

//    for(int i = 0; i < sz; i++) {
//        cout << "getp " << i << ' ' << getp(i) << endl;
//    }

    for(int i = 0; i < sz; i++)
        cout << a[getp(i)] << ' ';
    cout << endl;


//    int t = 1;
//    cin >> t;
//
//    while(t--)
//        solve();
}