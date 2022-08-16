#include <bits/stdc++.h>
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

const int MX = 200005;
int a[MX], b[MX];
int n;

int solve() {
    bool r0 = true;
    REP(i, n) if(b[i+1]!=i+1) r0=false;
    if(r0) return 0;

    int r = 0;

    if (b[n] != 0) {
        int p = n;
        while (p-1 > 0 && b[p-1] > 0 && b[p] == b[p-1] + 1)
            p--;
        if (b[p] == 1) {
            r = p - 1;
            while (--p > 0) {
                if (b[p] == 0)
                    continue;
                int v = b[p] - b[n];
                // cout << p << ", " << v << endl;
                if (p > v - 1) {
                    r = -1;
                    break;
                }
            }
            if (r != -1)
                return r;
        }
    }

    r = 0;
    REP(i, n) {
        if (b[i+1] == 0)
            continue;
        int mv = max(0, i + 1 - b[i+1] + 1);
        tmax(r, mv);
    }

    return r + n;
}

int main() {
    setIO();
    cin>>n;
    REP(i, n) cin >> a[i+1];
    REP(i, n) cin >> b[i+1];
    cout<<solve()<<"\n";
    return 0;
}