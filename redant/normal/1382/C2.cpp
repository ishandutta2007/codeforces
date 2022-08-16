#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PI;

#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define F first
#define S second
#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int SZ = 100005;
int n, m, k, x, y;
string aa, bb;
int a[SZ], b[SZ];
int fac = 0, flips = 0;

int getI(int i) {
    int r = 0;
    if (flips&1) r = fac - i;
    else r = i + fac;
    // cout << "getI " << i << " -> " << r << endl;
    return r;
}

char getA(int i) {
    int r = 0;
    if (flips&1) r = 1 - a[getI(i)];
    else r = a[getI(i)];
    // cout << (flips&1) << " getA " << i << " -> " << r << endl;
    return r;
}

void flip(int k) {
    // cout << "Flip " << k << endl;
    if(k==0) return;
    flips++;
    if(flips&1) fac+=k;
    else fac-=k;
}

void solve() {
    REP(i, n) {
        a[i] = (aa[i] == '0' ? 0 : 1);
        b[i] = (bb[i] == '0' ? 0 : 1);
    }
    // REP(i, n) {
    //     cout << a[i] << ", ";
    // }
    // cout << endl;

    // REP(i, n) {
    //     cout << b[i] << ", ";
    // }
    // cout << endl;

    VI res;
    fac=flips=0;
    for(int i = n - 1; i >= 0; i--) {
        // cout << "i = " << i << ", b[i] = " << b[i] << endl;
        if (b[i] != getA(i)) {
            // cout<<".."<<endl;
            if (b[i] == getA(0)) res.PB(0);
            res.PB(i);
            flip(i);
        }
    }
    cout<<res.size();
    REP(i, res.size()) cout<<" "<<(res[i]+1);
    cout<<"\n";
    // cout<<"-------------"<<endl;
}


int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n;        
        cin>>aa>>bb;
        solve();
    }
    
    return 0;
}