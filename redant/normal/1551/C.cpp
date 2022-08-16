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
string s[MX];
int a[MX];
int n;

int solve() {
    int r = 0;
    for (char c = 'a'; c <= 'e'; c++) {
        REP(i, n) {
            int m = s[i].length();
            int cnt = count(ALL(s[i]), c);
            a[i] = 2 * cnt - m;
        }
        int rr = 0, sum = 0;
        sort(a, a+n, greater<int>());
        REP(i, n) {
            sum += a[i];
            if (sum <= 0)
                break;
            ++rr;
        }
        tmax(r, rr);
    }
    return r; 
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n;
        REP(i, n) {
            cin>>s[i];
        }
        cout<<solve()<<"\n";
    }
    
    return 0;
}