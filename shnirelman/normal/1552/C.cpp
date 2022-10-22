#define _GLIBCXX_DEBUG
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
1
10 6
14 6
2 20
9 10
13 18
15 12
11 7

*/

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n * 2, -1);
    for(int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;

        if(x > y)
            swap(x, y);

        a[x - 1] = i;
        a[y - 1] = i + n;
    }

    int cur = k;
    for(int i = 0; i < n * 2; i++) {
        if(a[i] == -1) {
            a[i] = cur;
            cur++;
            if(cur == n)
                cur = n + k;
        }
    }

//    for(int i = 0; i < n * 2; i++) {
//        cout << a[i] << ' ';
//    }
//    cout << endl;
//    return ;

    int ans = 0;
    for(int i = 0; i < n * 2; i++) {
//        co
        if(a[i] >= n)
            continue;

        set<int> st;
        for(int j = i + 1; a[j] != a[i] + n; j++) {
            if(a[j] >= n && st.count(a[j] - n))
                st.erase(a[j] - n);
            else
                st.insert(a[j]);
        }

//        cout << "i : " << i << ' ' << st.size() << endl;
//        for(auto x : st)
//            cout << x << ' ';
//        cout << endl;

        ans += st.size();
    }

    cout << ans / 2 << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}