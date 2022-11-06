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
        lint n, k, x;
        cin >> n >> k >> x;
        string s;
        cin >> s;
        x--;
        vector<int> cnt;
        int tmp = 0;
        REP(i, s.size()+1) {
            if(i == s.size() || s[i] == 'a') {
                if(tmp > 0) {
                    cnt.push_back(tmp * k + 1);
                    tmp = 0;
                }
            } else {
                tmp++;
            }
        }
        vector<int> ans(cnt.size());
        double dmul = 1;
        lint mul = 1;
        IREP(i, cnt.size()) {
            if(dmul * cnt[i] > 2e18 || mul * cnt[i] > x || i == 0) {
                ans[i] = x / mul;
                x %= mul;
                FOR(j, i+1, cnt.size()) {
                    mul /= cnt[j];
                    ans[j] = x / mul;
                    x %= mul;
                    
                }
                break;
            }
            dmul *= cnt[i];
            mul *= cnt[i];
        }
        string anss = "";
        bool b = false;
        int ptr = 0;
        REP(i, s.size()) {
            if(s[i] == 'a') {
                anss += "a";
                b = false;
            } else {
                if(!b) {
                    REP(j, ans[ptr]) anss += "b";
                    ptr++;
                    b = true;
                }
            }
        }
        cout << anss << "\n";
    }
}