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
    vector<bool> prime(1000001, true);
    prime[1] = false;
    FOR(i, 2, 1000001) if(prime[i]) for(int j=i*2; j<1000001; j+=i) prime[j] = false;
    while(T--) {
        int n, e;
        cin >> n >> e;
        vector<int> a(n);
        REP(i, n) cin >> a[i];
        vector<lint> lp(n), rp(n);
        REP(i, e) {
            if(a[i] == 1 || prime[a[i]]) lp[i] = 1;
            if(a[n-1-i] == 1 || prime[a[n-1-i]]) rp[n-1-i] = 1;
        }
        REP(i, n) {
            if(!prime[a[i]] && i+e < n && (a[i+e] == 1 || prime[a[i+e]])) lp[i+e] = lp[i] + 1;
            else if(prime[a[i]] && i+e < n && (a[i+e] == 1 || prime[a[i+e]])) lp[i+e] = 1;
        }
        IREP(i, n) {
            if(!prime[a[i]] && i-e >= 0 && (a[i-e] == 1 || prime[a[i-e]])) rp[i-e] = rp[i] + 1;
            else if(prime[a[i]] && i-e >= 0 && (a[i-e] == 1 || prime[a[i-e]])) rp[i-e] = 1;
        }


        lint ans = 0;
        REP(i, n) {
            if(a[i] != 1) {
                ans += max(lp[i] * rp[i] - 1, 0LL);
            }
        }
        cout << ans << "\n";
    }
}