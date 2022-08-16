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

int n, k;
VI a, w;

LL solve() {
    sort(ALL(w));
    sort(ALL(a));
    int l = 0, r = n - 1;
    int lw = 0, rw = k - 1;
    LL rr = 0;
    while (lw <= rw) {
        if (w[lw] == 1) {
            rr += a[r];
            rr += a[r--];
            lw++;
            continue;
        }

        rr += a[r--];
        rr += a[l++];
        REP(j, w[rw] - 2)
            l++;
        rw--;
    }
    return rr;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n>>k;
        a.resize(n);
        w.resize(k);
        REP(i, n) cin >> a[i];
        REP(i, k) cin >> w[i];
        cout<<solve()<<"\n";
    }
    
    return 0;
}