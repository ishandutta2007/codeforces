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
void yes(bool expr) {cout << (expr ? "YES" : "NO") << "\n";}
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
        int l = 0;
        int r = n-1;
        int d1 = -1;
        int d2 = -1;
        while(l < r) {
            if(a[l] == a[r]) {
                l++;
                r--;
            } else {
                d1 = a[l];
                d2 = a[r];
                break;
            }
        }
        if(d1 == -1) {
            cout << "YES" << "\n";
            continue;
        }
        bool ok = true;
        l = 0;
        r = n-1;
        while(l < r) {
            if(a[l] == d1) l++;
            else if(a[r] == d1) r--;
            else if(a[l] == a[r]) {
                l++;
                r--;
            } else {
                ok = false;
                break;
            }
        }

        if(ok) {
            cout << "YES" << "\n";
            continue;
        }

        ok = true;
        l = 0;
        r = n-1;

        while(l < r) {
            if(a[l] == d2) l++;
            else if(a[r] == d2) r--;
            else if(a[l] == a[r]) {
                l++;
                r--;
            } else {
                ok = false;
                break;
            }
        }

        if(ok) {
            cout << "YES" << "\n";
            continue;
        }
        cout << "NO" << "\n";
    }
}