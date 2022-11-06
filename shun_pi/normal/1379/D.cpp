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
constexpr int INF = 2147483647;
void yes(bool expr) {cout << (expr ? "Yes" : "No") << "\n";}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    lint N, H, M, K;
    cin >> N >> H >> M >> K;
    vector<lint> m(N);
    REP(i, N) {
        lint hh, mm;
        cin >> hh >> mm;
        m[i] = (mm < M/2) ? mm : mm - M/2;
    }
    vector<lint> m2;
    REP(i, N) {
        m2.push_back(m[i]);
        m2.push_back(m[i]+M/2);
    }
    sort(ALL(m2));
    lint ans = N+1;
    lint t = -1;
    REP(i, N) {
        lint l = -1;
        lint r = 2*N;
        while(r-l > 1) {
            lint x = (l+r) / 2;
            if(m2[x] >= m2[i] + K) r = x;
            else l = x;
        }
        if(r-i-1 < ans) {
            ans = min(ans, r-i-1);
            t = m2[i];
        }
        
    }
    cout << ans << " " << (t+K)%(M/2) << endl;
    vector<int> idx;
    REP(i, N) {
        if(t < m[i] && m[i] < t+K) idx.push_back(i+1);
        else if(m[i] < t+K-(M/2)) idx.push_back(i+1);
    }
    REP(i, idx.size()) cout << idx[i] << (i!=idx.size()-1 ? " " : "");
    cout << "\n";
}