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

const int MX = 1000006;
vector<int> pr;
int d;

void sieve() {
    vector<bool> isP(MX, true);
    for (int i = 2; i < MX; i++) {
        if (!isP[i]) continue;
        pr.push_back(i);
        for (int j = i * i; j > 0 && j < MX; j += i)
            isP[j] = false;
    }
}

LL solve() {
    int p1 = *lower_bound(pr.begin(), pr.end(), 1+d);
    int p2 = *lower_bound(pr.begin(), pr.end(), p1+d);
    return 1ll * p1 * p2;
}

int main() {
    setIO();

    sieve();
    int t; cin>>t;
    while(t--) {
        cin>>d;
        cout<<solve()<<"\n";
    }
    
    return 0;
}