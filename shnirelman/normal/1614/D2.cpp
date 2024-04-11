#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 2e7 + 13;
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

vector<int> res;

void calc(int cur, const vector<pii>& p, int i) {
    if(i == p.size()) {
        res.push_back(cur);
        return;
    }

    for(int j = 0; j <= p[i].s; j++) {
        calc(cur, p, i + 1);
        cur *= p[i].f;
    }
}



int a[N], cnt[N];
int d[N];
//vector<int> dv[N];
int c[N];

pii ord[N];

//map<int, li> dp[N];
li dp[N];

//vector<int> ps[N];
//
//void calc_ps(int x) {
//    while(x > 1) {
//        int y = d[x];
//        ps.push_back(y);
//        while()
//    }
//}

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

    for(int i = 2; i < N; i++) {
        if(d[i] == 0) {
            d[i] = i;
            if(i * 1ll * i < N)
                for(int j = i * i; j < N; j += i)
                    d[j] = i;
        }
    }

    li ans = 0;

    for(int x = 0; x < N; x++) if(cnt[x] > 0) {
//        vector<int> dv;
//        deque<int> sm, lar;
//        for(int i = 1; i * i <= x; i++) {
//            if(x % i == 0) {
//                sm.push_front(i);
//                if(i * i != x)
//                    lar.push_back(x / i);
//            }
//        }
//
//        vector<int> dv(sm.size() + lar.size());
//        for(int i = 0; i < lar.size(); i++)
//            dv[i] = lar[i];
//        for(int i = 0; i < sm.size(); i++)
//            dv[i + lar.size()] = sm[i];

        vector<pii> p;
        int y = x;
        while(y > 1) {
            int d1 = d[y];
            p.emplace_back(d1, 0);
            while(y % d1 == 0) {
                y /= d1;
                p.back().s++;
            }
        }

        res.erase(res.begin(), res.end());
        calc(1, p, 0);
        vector<int> dv = res;
        sort(dv.rbegin(), dv.rend());

//        cout << x << endl;
//        for(auto y : dv)
//            cout << y << ' ';
//        cout << endl;
//        for(auto pr : p)
//            cout << pr.f << ' ' << pr.s << " || ";
//        cout << endl;

        for(int i = 0; i < dv.size(); i++) {
            dp[dv[i]] = dv[i] * 1ll * c[dv[i]];

            for(pii pr : p) if(x % (dv[i] * 1ll * pr.f) == 0){
                int y = dv[i] * pr.f;
                dp[dv[i]] = max(dp[dv[i]], dp[y] + dv[i] * 1ll * (c[dv[i]] - c[y]));
            }

//            int y = dv[i];
//            while(y > 1) {
//                int z = d[y];
//                dp[dv[i]] = max(dp[dv[i]], dp[dv[i] / z] + dv[i] * 1ll * (c[dv[i]] - c[dv[i] / z]));
//                cout << x << ' ' << i << ' ' << dv[i] << ' ' << z << ' ' << dv[i] / z << endl;
//                while(y % z == 0)
//                    y /= z;
//            }

//            for(int j = 0; j < i; j++) {
//                if(dv[j] % dv[i] == 0) {
//                    dp[i] = max(dp[i], dp[j] + dv[i] * 1ll * (c[dv[i]] - c[dv[j]]));
//                }
//            }

            ans = max(ans, dp[dv[i]]);
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