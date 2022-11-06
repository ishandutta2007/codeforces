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
        int n;
        cin >> n;
        vector<int> a(n);
        REP(i, n) cin >> a[i];
        vector<int> b(n);
        REP(i, n) cin >> b[i];
        vector<P> sa(n);
        REP(i, n) sa[i] = P(a[i], i);
        vector<P> sb(n);
        REP(i, n) sb[i] = P(b[i], i);
        sort(ALL(sa), greater<P>());
        sort(ALL(sb), greater<P>());
        int mia = a[sb[0].second];
        int mib = b[sa[0].second];
        set<int> ans;
        ans.insert(sa[0].second);
        ans.insert(sb[0].second);
        int aptr = 1;
        int bptr = 1;
        while(true) {
            if(aptr < n && sa[aptr].first > mia) {
                ans.insert(sa[aptr].second);
                chmin(mib, b[sa[aptr].second]);
                aptr++;
            } else if(bptr < n && sb[bptr].first > mib) {
                ans.insert(sb[bptr].second);
                chmin(mia, a[sb[bptr].second]);
                bptr++;
            } else break;
        }
        REP(i, n) {
            if(ans.find(i) == ans.end()) cout << '0';
            else cout << '1';
        }
        cout << "\n";

    }
}