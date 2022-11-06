#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
constexpr int MOD = 1000000007;
struct Pair {
    int idx;
    int value;
    bool operator<(const Pair& a) const
    {
        return value > a.value;
    };
};
int main()
{
    lint n, m, a, b;
    cin >> n >> m >> a >> b;
    lint g, x, y, z;
    cin >> g >> x >> y >> z;
    int map[n][m];
    int rowred[n][m-b+1];
    REP(i, n) {
        priority_queue<Pair> pq;
        REP(j, m) {
            map[i][j] = g;
            Pair p;
            p.idx = j;
            p.value = g;
            pq.push(p);
            if(j >= b-1) {
                while(true) {
                    Pair x = pq.top();
                    if(x.idx > j - b) {
                        rowred[i][j-b+1] = x.value;
                        break;
                    } else {
                        pq.pop();
                    }
                }
            }
            g = (g * x + y) % z;
        }    
    }
    lint ans = 0;
    REP(j, m-b+1) {
        priority_queue<Pair> pq;
        REP(i, n) {
            Pair p;
            p.idx = i;
            p.value = rowred[i][j];
            pq.push(p);
            if(i >= a-1) {
                while(true) {
                    Pair x = pq.top();
                    if(x.idx > i - a) {
                        //cout << x.value << endl;
                        ans += x.value;
                        break;
                    } else {
                        pq.pop();
                    }
                }
            }
        }
    }
    cout << ans << endl;
}