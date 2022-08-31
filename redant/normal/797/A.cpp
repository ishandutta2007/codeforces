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

int n, k;

void solve() {
    if (k == 1) {
        cout << n << endl;
        return;
    }
    VI ans;
    for (int f = 2; f <= n && SZ(ans) < k; f++) {
        if (n % f != 0)
            continue;
        while (n % f == 0) {
            ans.PB(f);
            n /= f;
            if (SZ(ans) == k - 1 && n > 1) {
                ans.PB(n);
                break;
            }
        }
    }

    if (SZ(ans) != k) cout << "-1\n";
    else {
        TRAV(x, ans) cout << x << " ";
        cout << endl;
    }
}

int main() {
    setIO();
    cin>>n>>k;
    solve();
    return 0;
}