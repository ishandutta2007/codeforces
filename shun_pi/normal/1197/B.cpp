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
    vector<int> a(n);
    REP(i, n) {
        cin >> a[i];
        a[i]--;
    }
    vector<int> idx(n);
    REP(i, n) {
        idx[a[i]] = i;
    }
    int l = idx[n-1];
    int r = idx[n-1];
    IREP(i, n-1) {
        if(idx[i] == l-1) {
            l--;
        } else if(idx[i] == r+1) {
            r++;
        } else {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}