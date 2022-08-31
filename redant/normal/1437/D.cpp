#include <iostream>

using namespace std;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int MX = 200005;
int a[MX];
int q[MX];
int n;

void pr(int d, int l, int r) {
    cout<<"d = " << d << ": ("<<l<<","<<r<<") : ";
    FOR(i, l, r) cout << q[i] << " ";
    cout<<endl;
}

int solve() {
    int l = 0, r = 0, p = 0;
    int d = -1;
    q[r++] = a[p++];
    while (l < r) {
        ++d;
        // pr(d, l,r);
        REP(i, r-l) {
            ++l;
            int x = -1;
            if (p < n) {
                x = q[r++] = a[p++];
            }
            while (x != -1 && p < n && a[p] > x) {
                x = q[r++] = a[p++];
            }
        }
        // pr(d, l, r);
    }
    return d;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n;
        REP(i, n) {
            cin>>a[i];
        }
        cout<<solve()<<"\n";
    }
    
    return 0;
}