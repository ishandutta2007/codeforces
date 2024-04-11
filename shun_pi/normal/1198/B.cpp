#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
constexpr int MOD = 1000000007;
int main()
{
    int n;
    cin >> n;
    int nn = 1;
    while(nn < n) {
        nn *= 2;
    }
    vector<int> seg(2*nn - 1, 0);
    FOR(i, nn-1, nn-1 + n) cin >> seg[i];
    int q;
    cin >> q;
    REP(qq, q) {
        int mode;
        cin >> mode;
        if(mode == 1) {
            int p, x;
            cin >> p >> x;
            int ld = nn / 2;
            int lr = nn / 2;
            int idx = 0;
            while(true) {
                if(idx >= nn-1) {
                    seg[idx] = x;
                    break;
                }
                if(seg[2*idx+1] < seg[idx]) seg[2*idx+1] = seg[idx];
                if(seg[2*idx+2] < seg[idx]) seg[2*idx+2] = seg[idx];
                seg[idx] = 0;
                if(p <= lr) {
                    idx = 2*idx+1;
                    ld /= 2;
                    lr -= ld;
                } else {
                    idx = 2*idx+2;
                    ld /= 2;
                    lr += ld;
                }
            }
        } else {
            int x;
            cin >> x;
            if(x > seg[0]) {
                seg[0] = x;
            }
        }
    }
    vector<int> ans(n);
    REP(i, n) {
        ans[i] = seg[nn-1 + i];
        int j = nn-1 + i;
        while(true) {
            j = (j - 1) / 2;
            if(ans[i] < seg[j]) ans[i] = seg[j];
            if(j == 0) break;
        }
    }
    REP(i, n) cout << ans[i] << (i!=n-1 ? " " : "");
    cout << endl;
}