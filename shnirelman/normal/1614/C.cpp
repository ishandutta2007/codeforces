#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 2e5 + 113;
const int M = 1e9 + 7;
const int A = 26;

int sum(int a, int b) {
    a += b;
    return (a >= M ? a - M : a);
}

int mul(int a, int b) {
    return a * 1ll * b % M;
}

int dif(int a, int b) {
    return sum(a, M - b);
}

int pw2[N];

int l[N], r[N], x[N];

void solve() {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        cin >> l[i] >> r[i] >> x[i];

        l[i]--;
    }

    int ans = 0;

//    int pw2 = 1;
    for(int b = 0; b < 30; b++) {
//        vector<int> add(n + 1, 0);
        for(int i = 0; i < m; i++) {
            if((x[i] & (1 << b)) != 0) {
                ans = sum(ans, mul(pw2[n - 1], pw2[b]));
                break;
            }
        }
//
//        int k = 0, cur = 0;
//        for(int i = 0; i < n; i++) {
//            cur += add[i];
//            if(cur == 0)
//                k++;
//        }

//        for(int i = 1; i <= k; i += 2)
//        if(k > 0) {
//
////            mul(C(k, i), pw2[n - k])
//        }

//        pw2 = mul(pw2, 2);
    }

    cout << ans << endl;
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    pw2[0] = 1;
    for(int i = 1; i < N; i++) {
        pw2[i] = mul(pw2[i - 1], 2);
    }

    int t;
    cin >> t;

    while(t--)
        solve();
}