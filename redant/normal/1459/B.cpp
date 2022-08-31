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
#define ALL(v) (v).begin(),(v).end()
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define TRAV(a,x) for (auto& a : x)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

// const int MX = 101;
// int res[MX];
// int vis[2*MX][2*MX][4]; // +3][2*MX+3];

// int dx[4] = {0, 1, 0, -1};
// int dy[4] = {-1, 0, 1, 0};

// void run() {
//     res[0] = 1;
//     queue<int> qx, qy, qd;
//     qx.push(MX), qy.push(MX), qd.push(-1);
//     REP(turns, 10) { // MX) {
//         int k = 1 + turns;
//         set<PI> s;
//         for (int qs = qx.size(); qs--; ) {
//             int x = qx.front(); qx.pop();
//             int y = qy.front(); qy.pop();
//             int d = qd.front(); qd.pop();
//             REP(i, 4) {
//                 if (d == -1 || (d+i)&1) {
//                     int nx = x + dx[i], ny = y + dy[i], nd = i;
//                     if (vis[nx][ny][nd] != k) {
//                         vis[nx][ny][nd] = k;
//                         // cout << k << " : " << (nx - MX) << ", " << (ny - MX) << endl;
//                         s.insert(MP(nx, ny));
//                         qx.push(nx);
//                         qy.push(ny);
//                         qd.push(nd);
//                     }
//                 }
//             }
//         }
//         res[k] = s.size();
//     }

//     REP(i, 10) {
//         cout << res[i] << ", ";
//     }
//     cout << endl;
// }

int main() {
    setIO();
    // run();
    int t=1; // ; cin>>t;
    while(t--) {
        LL n;
        cin>>n;        
        LL r = 1 + ( 3 * n * (n + 4) + 2 - (n&1?-1:1) * ( n * (n + 4) + 2) ) / 8;
        cout << r << endl;
    }
    
    return 0;
}