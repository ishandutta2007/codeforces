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
1
2
1 7

1
3
1 5 4
*/

//vector<int> A = {}

bool query(int a, int b, int c) {
    cout << "? " << a + 1 << ' ' << b + 1 << ' ' << c + 1 << endl;
    int r;
    cin >> r;

    if(r == -1)
        exit(0);

    return (r == 1);
}

bool answer(vector<int> a) {
    cout << "! " << a.size() << ' ';
    for(auto x : a)
        cout << x + 1 << ' ';
    cout << endl;
}



void solve() {
//    set<int> st;
//    vector<int> a(n, -1);
//    for(int i = 2; i < n; i++) {
//        int res = query(0, 1, i);
//        a[i] = res;
//        st.insert(res);
//    }
//
//    if(st.size() == )
    int n;
    cin >> n;

    int x = -1, y = -1;

    for(int i = 0; i < n; i += 3) {
        if(query(i, i + 1, i + 2))
            y = i;
        else
            x = i;
    }

    int fr = -1, inv = -1;

//    for(int i = 0; i < 3; i++) {
//        if(query())
//    }


    for(int i = y; i < y + 3; i++) {
        if(query(x, x + 1, i))
            fr = i;
    }

    if(fr == -1) {
        inv = x;
        for(int i = y; i < y + 3; i++) {
            if(query(inv, i == y ? y + 1 : y, i == y + 2 ? y + 1 : y + 2))
                fr = (i == y ? y + 1 : y);
        }
    } else {
        for(int i = x; i < x + 3; i++) {
            if(!query(fr, i == x ? x + 1 : x, i == x + 2 ? x + 1 : x + 2))
                inv = (i == x ? x + 1 : x);
        }
    }

    vector<int> a;
    for(int i = 0; i < n; i++) {
        if(inv == i || fr != i && !query(inv, fr, i))
            a.push_back(i);
    }

    answer(a);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
//
    while(t--)
        solve();
}