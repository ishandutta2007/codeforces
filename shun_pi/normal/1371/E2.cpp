#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using P = pair<lint, lint>;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
constexpr int MOD = 1000000007;
constexpr int INF = 2147483647;
void yes(bool expr) {
  cout << (expr ? "Yes" : "No") << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int p, n;
    cin >> n >> p;
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    sort(ALL(a));
    int amax = a[n-1];
    int amin = a[0];
    REP(i, n) if(a[i] - i > amin) amin = a[i] - i;
    vector<int> ans;
    int l = max(amin - 1, amax - n);
    int r = amax;
    while(r-l > 1) {
        int m = (l + r) / 2;
        int idx = 0;
        int xnow = m;
        bool flg = true;
        //cout << "m" << m << endl;
        while(xnow-m < n) {
            if(idx == n || a[idx] > xnow) {
                if(idx-(xnow-m) <= 0 || idx-(xnow-m) >= p) {
                    flg = false;
                    break;
                }
                xnow++;
            } else {
                idx++;
            }
        }
        if(flg) l = m; 
        else r = m;
    }
    FOR(i, max(amin, amax - n + 1), l+1) ans.push_back(i);
    cout << ans.size() << endl;
    REP(i, ans.size()) cout << ans[i] << (i!=ans.size()-1 ? " " : "");
    cout << "\n";
}