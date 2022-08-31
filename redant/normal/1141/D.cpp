#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

typedef long long LL;
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<PI> VPI;

template<class T> bool tmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool tmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define F first
#define S second
#define SZ(x) (int)(x).size()
#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)
#define TRAV(a,x) for (auto& a : x)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int MX = 150010;
int n;
string s1, s2;
const int q = '?';

void solve() {
    VI c1[150], c2[150];
    REP(i, n) {
        c1[s1[i]].PB(i+1);
        c2[s2[i]].PB(i+1);
    }
    VPI res;
    int p1 = SZ(c1[q]) - 1;
    int p2 = SZ(c2[q]) - 1;
    for (int ch = 'a'; ch <= 'z'; ch++) {
        int mn = min(SZ(c1[ch]), SZ(c2[ch]));
        int rs = SZ(res);
        REP(i, mn) res.PB(MP(c1[ch][i], c2[ch][i]));
        for (int i = mn; i < SZ(c1[ch]) && p2 >= 0; i++, p2--)
            res.PB(MP(c1[ch][i], c2[q][p2]));
        for (int i = mn; i < SZ(c2[ch]) && p1 >= 0; i++, p1--)
            res.PB(MP(c1[q][p1], c2[ch][i]));
        // if (rs < SZ(res)) {
        //     cout << (char (ch)) << endl;
        //     REP(i, SZ(res) - rs)
        //         cout << res[rs+i].F << ", " << res[rs+i].S << endl;
        // }
    }

    // cout << (char ('?')) << endl;
    while (p1 >= 0 && p2 >= 0) {
        res.PB(MP(c1[q][p1--], c2[q][p2--]));
    }

    cout << SZ(res) << "\n";
    TRAV(x, res) cout << x.F << " " << x.S << "\n";
}

int main() {
    setIO();
    cin>>n>>s1>>s2;
    solve();    
    return 0;
}