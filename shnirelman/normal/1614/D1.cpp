#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 5e6 + 13;
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


int a[N], cnt[N];
//vector<int> dv[N];
int c[N];

pii ord[N];

//map<int, li> dp[N];
li dp[N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

//    int g = 0;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
//        g = __gcd(g, a[i]);
    }

    for(int i = 1; i < N; i++) {
//        if(i % 10000 == 0)
//            cout << i << endl;
        for(int j = i; j < N; j += i) {
//            dv[j].push_back(i);
            c[i] += cnt[j];
        }
    }

    li ans = 0;

    for(int x = 0; x < N; x++) if(cnt[x] > 0) {
//        vector<int> dv;
        deque<int> sm, lar;
        for(int i = 1; i * i <= x; i++) {
            if(x % i == 0) {
                sm.push_front(i);
                if(i * i != x)
                    lar.push_back(x / i);
            }
        }

        vector<int> dv(sm.size() + lar.size());
        for(int i = 0; i < lar.size(); i++)
            dv[i] = lar[i];
        for(int i = 0; i < sm.size(); i++)
            dv[i + lar.size()] = sm[i];

        for(int i = 0; i < dv.size(); i++) {
            dp[i] = dv[i] * 1ll * c[dv[i]];
            for(int j = 0; j < i; j++) {
                if(dv[j] % dv[i] == 0) {
                    dp[i] = max(dp[i], dp[j] + dv[i] * 1ll * (c[dv[i]] - c[dv[j]]));
                }
            }

            ans = max(ans, dp[i]);
        }
    }

    cout << ans << endl;

//    dp[n][g] = 0;
//    for(int i = n - 1; i >= 0; i--) {
//
//    }



//    for(int i = 1; i < N; i++) {
//        ord[i] = {c[i], i};
//    }
//
//    sort(ord + 1, ord + N);
//
//    for(int i = 0; i < n; i++) {
//        dp[0][a[i]] = a[i];
//    }

//    for(int i = 1; i < n; i++) {
//        for(auto p : dp[i - 1]) {
//            int x = p.f;
//            if(c[x] > i) {
//                dp[i][x] = max(dp[i][x], p.s + x);
//            } else {
//                for(int y : dv[x]) if(c[y] > i) {
//                    dp[i][y] = max(dp[i][y], p.s + y);
//                }
//            }
//        }
//    }
//
//    li ans = 0;
//    for(auto p : dp[n - 1])
//        ans = max(ans, p.s);
//
//    cout << ans << endl;

//    int lf = 1;
//    for(int i = 1; i < n; i++) {
//        while(ord[lf].f <= i)
//            lf++;
//
//        for(int j = lf; j < N; j++) {
//            int x = ord[j].s;
//            for(int y : dv[x]) {
//
//            }
//        }
//    }
}