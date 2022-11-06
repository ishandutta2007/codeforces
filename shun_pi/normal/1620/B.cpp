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
        lint w, h;
        cin >> w >> h;
        vector<vector<lint>> lat(4);
        REP(i, 4) {
            int k;
            cin >> k;
            lat[i] = vector<lint>(k);
            REP(j, k) cin >> lat[i][j];
        }
        lint ans = 0;
        chmax(ans, (lat[0][lat[0].size()-1] - lat[0][0]) * h);
        chmax(ans, (lat[1][lat[1].size()-1] - lat[1][0]) * h);
        chmax(ans, (lat[2][lat[2].size()-1] - lat[2][0]) * w);
        chmax(ans, (lat[3][lat[3].size()-1] - lat[3][0]) * w);
        cout << ans << "\n";
    }
}