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
int a[SZ];
int n, m;

double solve() {
    LL l = 1, r = n;
    double speeda = 1, speedb = 1;
    double posa = 0, posb = m;
    double res = 0;
    while (l <= r) {
        double da = a[l] - posa;
        double db = posb - a[r];
        double t = 0;
        if (da * speedb < db * speeda) {
            t = da / speeda;
            l++;
            posa += speeda * t;
            posb -= speedb * t;
            speeda += 1;
        } else {
            t = db / speedb;
            r--;
            posa += speeda * t;
            posb -= speedb * t;
            speedb += 1;
        }
        res += t;
    }

    res += abs(posa-posb) / (speedb + speeda);

    return res;
}

int main() {
    setIO();
    int t; cin>>t;
    cout << fixed;
    cout << setprecision(10);
    while(t--) {
        cin>>n>>m;
        REP(i, n) {
            cin>>a[i+1];
        }
        cout<<solve()<<"\n";
    }
    
    return 0;
}