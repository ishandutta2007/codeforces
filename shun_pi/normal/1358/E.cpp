#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
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
    lint n;
    cin >> n;
    lint n1 = (n+1)/2;
    lint n2 = n - n1;
    vector<lint> a1(n1);
    REP(i, n1) cin >> a1[i];
    lint a2;
    cin >> a2;
    lint asum = a2*n2;
    REP(i, n1) asum += a1[i];
    if(asum > 0) {
        cout << n << endl;
        return 0;
    }
    if(a2 >= 0 && asum <= 0) {
        cout << -1 << endl;
        return 0;
    }
    lint Smin = 0;
    lint Snow = 0;
    int i = 0;
    IFOR(k, n2+1, n) {
        asum -= a2;
        Snow += a2-a1[i];
        i++;
        if(Snow < Smin) Smin = Snow;
        //cout << k << " " << asum << " " << Smin << endl;
        if(asum + Smin <= 0) continue;
        cout << k << endl;
        return 0;
    }
    cout << -1 << endl;
}