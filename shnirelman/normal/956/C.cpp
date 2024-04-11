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

*/


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<bool> b(n, false);
    set<int> st;
    int mx = -1;
    int cur = 0;
    li ans = 0;
    for(int i = 0; i < n; i++) {
        st.insert(-i);
        if(mx < a[i]) {
            mx = a[i];
            while(cur <= mx) {
                b[-*st.begin()] = true;
                st.erase(st.begin());
                cur++;
            }
        }

//        ans += cur - a[i] - 1;
//        cout << i << ' ' << cur << endl;
    }

//    for(int i = 0; i < n; i++)
//        cout << b[i] << ' ';
//    cout << endl;

    cur = 0;
    for(int i = 0; i < n; i++) {
        cur += b[i];
        ans += cur - a[i] - 1;
    }

    cout << ans << endl;

//    int mx = -1;
//    vector<int> b;
//    for(int i = 0; i < n; i++) {
//        if(a[i] > mx) {
//            b.push_back(i);
//            mx = a[i];
//        }
//    }
//
//    int r = n;
//    for(int ind = b.size() - 1; ind >= 0; ind--) {
//        int i = b[ind];
//        int l = (ind == 0 ? -1 : b[ind - 1]);
//
//    }
}