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
    int amax = 0;
    REP(i, n) if(a[i] > amax) amax = a[i];
    sort(ALL(a));
    vector<int> ans;
    FOR(x, 1, amax) {
        int f = 1;
        int idx = 0;
        int xnow = x;
        bool flg = true;
        //cout << "x" << x << endl;
        while(xnow-x < n) {
            if(idx == n || a[idx] > xnow) {
                //cout << idx-(xnow-x) << endl;
                f = f * (idx-(xnow-x)) % p;
                if(f == 0) {
                    flg = false;
                    break;
                }
                xnow++;
            } else {
                idx++;
            }
        }
        if(flg) ans.push_back(x);
    }
    cout << ans.size() << endl;
    REP(i, ans.size()) cout << ans[i] << (i!=ans.size()-1 ? " " : "");
    cout << "\n";
}