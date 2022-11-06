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
    int q;
    cin >> q;
    vector<int> a;
    vector<tuple<int, int, int>> b;
    while(q--) {
        int m, x;
        cin >> m >> x;
        if(m == 1) {
            a.push_back(x);
        } else {
            int y;
            cin >> y;
            b.push_back(make_tuple(a.size(), x, y));
        }
    }
    int ptr = b.size() - 1;
    map<int, int> mp;
    REP(i, 500100) mp[i] = i;
    IREP(i, a.size()+1) {
        if(i < a.size()) a[i] = mp[a[i]];
        while(ptr >= 0 && get<0>(b[ptr]) == i) {
            mp[get<1>(b[ptr])] = mp[get<2>(b[ptr])];
            ptr--;
        }
    }
    REP(i, a.size()) cout << a[i] << (i!=a.size()-1 ? " " : "");
    cout << "\n";
}