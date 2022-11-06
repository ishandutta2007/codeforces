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
    int n, k;
    cin >> n >> k;
    cout << "? ";
    FOR(i, 1, k+1) cout << i << (i!=k ? " " : "");
    cout << endl;
    cout.flush();
    int pos, val;
    cin >> pos >> val;
    vector<bool> side(k+2, false);

    FOR(i, 1, k+1) {
        if(i == pos) continue;
        cout << "? ";
        FOR(j, 1, k+2) {
            if(i != j) cout << j << (j!=k+1 ? " " : "");
        }
        cout << endl;
        cout.flush();
        int post, valt;
        cin >> post >> valt;
        if(pos != post) {
            side[i] = true;
        }
    }
    int ans = 1;
    FOR(i, 1, k+1) {
        if(side[i]) ans++;
    }
    cout << "? ";
    FOR(i, 1, k+2) {
        if(i != pos) cout << i << (i!=k+1 ? " " : "");
    }
    cout << endl;
    cout.flush();
    int posz, valz;
    cin >> posz >> valz;
    if((side[posz] && valz > val) || (!side[posz] && valz < val)) {
        ans = k + 1 - ans;
    }
    cout << "! " << ans << endl;
    cout.flush();
}