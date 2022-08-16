#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int MX = 100005;
int a[MX];
int n;

int solve() {
    REP(i ,n) {
        int j = i;
        while (j+1 < n && a[j+1] == a[i])
            ++j;
        // cout << a[i] << ": " << i << " - " << j << endl;
        if (j > i) {
            a[j]++;
            i = j - 1;
        }
    }
    set<int> b;
    REP(i, n) b.insert(a[i]);
    // REP(i, n) {
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    return b.size();
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