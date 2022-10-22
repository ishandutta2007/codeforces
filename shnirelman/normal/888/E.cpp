#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 1e7 + 13;
const int LOGN = 20;
const int A = 27;

int m;

int sum(int a, int b) {
    a += b;
    if(a >= m)
        a -= m;
    return a;
}

set<int> get(int n, vector<int> a) {
    vector<int> res(1, 0);
    for(int i = 0; i < n; i++) {
        int sz = res.size();

        for(int j = 0; j < sz; j++) {
            res.push_back(sum(res[j], a[i]));
        }
    }

    return set<int>(res.begin(), res.end());
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n >> m;

    int n1 = n / 2;
    int n2 = n - n1;

    vector<int> a(n1), b(n2);
    for(int i = 0; i < n1; i++) {
        cin >> a[i];
        a[i] %= m;
    }

    for(int i = 0; i < n2; i++) {
        cin >> b[i];
        b[i] %= m;
    }

    set<int> st1 = get(n1, a), st2 = get(n2, b);

//    for(auto x : st1)
//        cout << x << ' ';
//    cout << endl;
    int ans = 0;
    for(auto x : st1) {
        ans = max(ans, x);

        int y = *st2.rbegin();
        ans = max(ans, sum(x, y));

        auto it = st2.lower_bound(m - x);
        if(it == st2.begin())
            continue;
        it--;
        ans = max(ans, sum(x, *it));
    }

    ans = max(ans, *st2.rbegin());

    cout << ans << endl;
}