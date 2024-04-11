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
int N;
int bit[1000010];
void add(int a, int w) {
    while(a <= N) {
        bit[a] += w;
        a += a & -a;
    }
}
int sum(int a) {
    int s = 0;
    while(a > 0) {
        s += bit[a];
        a -= a & -a;
    }
    return s;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    lint q;
    cin >> N >> q;
    REP(i, N) {
        int A;
        cin >> A;
        add(A, 1);
    }
    REP(i, q) {
        int k;
        cin >> k;
        if(k < 0) {
            k = -k;
            int l = 0;
            int r = N;
            while(r-l > 1) {
                int m = (l+r) / 2;
                if(sum(m) >= k) {
                    r = m;
                } else {
                    l = m;
                }
            }
            //cout << r << endl;
            add(r, -1);
        } else {
            add(k, 1);
        }
    }
    REP(i, N) {
        if(sum(i+1) > 0) {
            cout << (i+1) << endl;
            return 0;
        }
    }
    cout << 0 << endl;

}