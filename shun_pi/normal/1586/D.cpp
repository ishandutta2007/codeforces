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
    int n;
    cin >> n;
    vector<int> next(n, -1);
    REP(i, n) {
        vector<int> q(n, 2);
        q[i] = 1;
        cout << "? ";
        REP(i, n) cout << q[i] << (i!=n-1 ? " " : "");
        cout << "\n";
        cout.flush();
        int a;
        cin >> a;
        if(a > 0 && a-1 != i) next[a-1] = i;
    }
    REP(i, n) {
        vector<int> q(n, 1);
        q[i] = 2;
        cout << "? ";
        REP(i, n) cout << q[i] << (i!=n-1 ? " " : "");
        cout << "\n";
        cout.flush();
        int a;
        cin >> a;
        if(a > 0 && a-1 != i) next[i] = a-1;
    }

    vector<int> ans(n);
    set<int> st;
    REP(i, n) st.insert(i);
    REP(i, n) if(next[i] != -1) st.erase(next[i]);
    int s = *st.begin();
    int num = 1;
    while(true) {
        ans[s] = num;
        if(next[s] == -1) break;
        s = next[s];
        num++;
    }

    cout << "! ";
    REP(i, n) cout << ans[i] << (i!=n-1 ? " " : "");
    cout << "\n";
    cout.flush();
}