#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using P = pair<int, int>;
using PL = pair<lint, lint>;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
constexpr int MOD = 1000000007;
constexpr lint B1 = 1532834020;
constexpr lint M1 = 2147482409;
constexpr lint B2 = 1388622299;
constexpr lint M2 = 2147478017;
constexpr int INF = 2147483647;
void yes(bool expr) {cout << (expr ? "Yes" : "No") << "\n";}
template<class T>void chmax(T &a, const T &b) { if (a<b) a=b; }
template<class T>void chmin(T &a, const T &b) { if (b<a) a=b; }
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int n, a, b;
        cin >> n >> a >> b;
        vector<int> ans(n);
        ans[0] = a;
        ans[n-1] = b;
        int tmp = 1;
        IFOR(i, 1, n-1) {
            while(tmp == a || tmp == b) tmp++;
            ans[i] = tmp;
            tmp++;
        } 
        int mi = 1e9;
        int ma = 0;
        REP(i, n/2) chmin(mi, ans[i]);
        FOR(i, n/2, n) chmax(ma, ans[i]);
        if(mi != a || ma != b) {
            cout << -1 << "\n";
        } else {
            REP(i, n) cout << ans[i] << (i!=n-1 ? " " : "");
            cout << "\n";
        }

    }
}