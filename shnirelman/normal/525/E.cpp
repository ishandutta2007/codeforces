#include <bits/stdc++.h>

#define f first
#define s second
//#define int long long

using namespace std;
using li = long long;
using  pii = pair<int, int>;

const li INF = 1e18;
const int N = 20;
//const int M = 1e9 + 7;
//
//int sum(int a, int b) {
//    int res = a + b;
//    if(res >= M)
//        res -= M;
//    return res;
//}

li p[N];
int cnt[1 << N];

vector<map<li, int>> get1(vector<int> a) {
    int n = a.size();

    vector<map<li, int>> res(26);

    vector<li> s1(1 << n, 0), s2(1 << n, 0);
    for(int mask = 0; mask < (1 << n); mask++) {
        for(int i = 0; i < n; i++)
            if(mask & (1 << i)) {
                s1[mask] += a[i];
                if(a[i] >= N || p[a[i]] == 0)
                    s2[mask] = INF;
                else
                    s2[mask] += p[a[i]];
            }
    }

    for(int mask = 0; mask < (1 << n); mask++) {
        for(int sub = mask; sub > 0; sub = (sub - 1) & mask) {
//            if(cnt[sub] == k) {
                li sum = s2[sub] + s1[mask ^ sub];
//                for(int i = 0; i < n; i++)
//                    if(i & sub)
//                        sum += p[a[i]];
//                    else if(i & mask)
//                        sum += a[i];

                if(sum < INF)
                    res[cnt[sub]][sum]++;
//            }
        }

        int sub = 0;
//        if(cnt[sub] == k) {
            li sum = s2[sub] + s1[mask ^ sub];
            if(sum < INF)
                res[cnt[sub]][sum]++;
//        }
    }

    return res;
}

vector<map<li, int>> get2(vector<int> a) {
    int n = a.size();

    vector<map<li, int>> res(26);

    vector<li> s1(1 << n, 0), s2(1 << n, 0);
    for(int mask = 0; mask < (1 << n); mask++) {
        for(int i = 0; i < n; i++)
            if(mask & (1 << i)) {
                s1[mask] += a[i];
                if(a[i] >= N || p[a[i]] == 0)
                    s2[mask] = INF;
                else
                    s2[mask] += p[a[i]];
            }
    }

    for(int mask = 0; mask < (1 << n); mask++) {
        for(int sub = mask; sub > 0; sub = (sub - 1) & mask) {
//            if(cnt[sub] <= k) {
                li sum = s2[sub] + s1[mask ^ sub];
//                for(int i = 0; i < n; i++)
//                    if(i & sub)
//                        sum += p[a[i]];
//                    else if(i & mask)
//                        sum += a[i];

                if(sum < INF)
                    for(int i = cnt[sub]; i < res.size(); i++)
                        res[i][sum]++;
//            }
        }

        int sub = 0;
//        if(cnt[sub] <= k) {
            li sum = s2[sub] + s1[mask ^ sub];
            if(sum < INF)
                for(int i = cnt[sub]; i < res.size(); i++)
                    res[i][sum]++;
//        }
    }

//    for(int i = 0; i < res.size(); i++) {
//        for(auto pp : res[i])
//            cout << i << ' ' << pp.f << ' ' <<pp.s << endl;
//    }

    return res;
}
/*
2 2 7
4 3

*/

signed main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int n, k;
    li s;
    cin >> n >> k >> s;

    p[0] = 1;
    for(int i = 1; p[i - 1] <= s; i++) {
        p[i] = p[i - 1] * i;
//        cout << p[i] << endl;
    }

    for(int i = 0; i < (1 << N); i++) {
        for(int j = 0; j < N; j++)
            if(i & (1 << j))
                cnt[i]++;
    }

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> lf, rg;
    for(int i = 0; i < n / 2; i++)
        lf.push_back(a[i]);
    for(int i = n / 2; i < n; i++)
        rg.push_back(a[i]);

    auto r1 = get1(lf);
    auto r2 = get2(rg);

    li ans = 0;
    for(int i = 0; i <= k; i++) {


        for(auto pp : r1[i]) {
            ans += pp.s * 1ll * r2[k - i][s - pp.f];
//            cout << i << ' ' << pp.f << ' ' << pp.s << ' ' << r2[k - i][s - pp.f] << endl;
        }

    }

    cout << ans;
}