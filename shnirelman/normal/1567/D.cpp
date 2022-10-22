#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pli = pair<li, li>;
//using matr

const li INF = 2e18 + 13;
const int N = 3e5 + 13;
const int M = 998244353;
const int B = 300;
const int A = 26;
const ld e = 1e-8;
const int LOGN = 20;
const int K = 170;

mt19937 rnd(0);

/*
*/


void solve() {
    int n, s;
    cin >> s >> n;

    vector<int> a(n, 0);
    int cur = 0;
    int left = n;

    for(int pw = 1000 * 1000 * 1000; pw >= 1; pw /= 10) {
        while(s >= pw + left - (a[cur] == 0)) {
//            cout << pw << ' ' << s << ' ' << left << ' '<< a[cur] << endl;
            if(a[cur] == 0)
                left--;
            a[cur] += pw;
            s -= pw;
            cur = (cur == n - 1 ? 0 : cur + 1);
        }
    }

    for(auto x : a)
        cout << x << ' ';
    cout << endl;
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);
    int t;
    cin >> t;

    while(t--)
        solve();
}