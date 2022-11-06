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
        if(abs(a-b) >= 2 || a+b > n-2) {
            cout << -1 << "\n";
            continue;
        }
        vector<int> ans(n);
        if(a != b) {
            int rest = n - 2*max(a, b) - 1;
            REP(i, 2*max(a, b)+1) {
                if(i%2 == 0) ans[i] = i/2+1+rest;
                else ans[i] = i/2+max(a, b)+2+rest;
            }
            FOR(i, 2*max(a, b)+1, n) {
                ans[i] = rest;
                rest--;
            }
            if(a < b) {
                REP(i, n) ans[i] = n+1 - ans[i];
            }
        } else {
            REP(i, 2*a+2) {
                if(i%2 == 0) ans[i] = i/2+1;
                else ans[i] = i/2+a+2;
            }
            FOR(i, 2*a+2, n) {
                ans[i] = i+1;
            }
        }
        REP(i, n) cout << ans[i] << (i!=n-1 ? " " : "");
        cout << "\n";
    }
}