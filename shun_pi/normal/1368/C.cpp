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
    int n;
    cin >> n;
    vector<int> x;
    vector<int> y;
    x.push_back(0);
    y.push_back(0);
    REP(i, n+1) {
        x.push_back(i);
        y.push_back(i+1);
        x.push_back(i+1);
        y.push_back(i);
        x.push_back(i+1);
        y.push_back(i+1);
    }
    cout << x.size() << "\n";
    REP(i, x.size()) {
        cout << x[i] << " " << y[i] << "\n";
    }
}