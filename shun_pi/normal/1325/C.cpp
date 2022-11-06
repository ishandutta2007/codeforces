#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
constexpr int MOD = 1000000007;
constexpr int INF = 2147483647;
int main()
{
    int n;
    cin >> n;
    vector<int> nbr(n, 0);
    vector<int> a(n-1);
    vector<int> b(n-1);
    REP(i, n-1) {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
        nbr[a[i]]++;
        nbr[b[i]]++;
    }
    int idx1 = 0;
    int idx2 = 0;
    REP(i, n) {
        if(nbr[i] == 1) idx2++;
    }
    vector<int> ans(n-1);
    REP(i, n-1) {
        if(nbr[a[i]] == 1 || nbr[b[i]] == 1) {
            ans[i] = idx1;
            idx1++;
        } else {
            ans[i] = idx2;
            idx2++;
        }
    }
    REP(i, n-1) cout << ans[i] << endl;
}