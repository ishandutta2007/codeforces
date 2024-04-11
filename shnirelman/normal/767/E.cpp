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


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];

    }

    vector<int> w(n);
    for(int i = 0; i < n; i++)
        cin >> w[i];

    set<pii> st;
    li ans = 0;
    vector<bool> res(n, false);
    for(int i = 0; i < n; i++) {
        if(a[i] % 100 == 0)
            continue;
        st.insert({w[i] * (100 - a[i] % 100), i});
        m -= a[i] % 100;

        if(m < 0) {
            ans += st.begin()->f;
            res[st.begin()->s] = true;
            st.erase(st.begin());
            m += 100;
        }
    }

    cout << ans << '\n';
    for(int i = 0; i < n; i++) {
        if(res[i])
            cout << (a[i] + 99) / 100 << ' ' << 0 << '\n';
        else
            cout << a[i] / 100 << ' ' << a[i] % 100 << '\n';
    }
}