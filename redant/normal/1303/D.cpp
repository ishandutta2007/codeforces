#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define debug(x) cerr << #x << " = " << x << ", line = " << __LINE__ << endl

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

LL n, m;
map<LL, int> pows;
int have[61];

void preprocess() {
    LL r = 1; 
    for (int i = 0; i < 62; i++) {
        pows[r] = i;
        r *= 2;
    }
}

int solve() {
    int r = 0;
    for (int i = 0; i <= 60; i++) {
        if (i > 0) {
            have[i] += have[i-1] / 2;
        }
        if(!(n & (1ll << i))) {
            continue;
        }
        // cout<<"n = "<<n<<", Need "<<i<<endl;
        int j = i;
        for(; j <= 60 && !have[j]; j++){}
        // cout<<"Have "<<j<<endl;
        if (j > 60) return -1;
        have[j]--;
        r += j - i;
        if (i != j) i = j - 1;
    }
    return r;
}

int main() {
    setIO();
    int t; cin>>t;
    preprocess();
    while(t--) {
        cin>>n>>m;
        memset(have, 0, sizeof have);
        while (m--) {
            LL x; cin >> x;
            have[pows[x]]++;
        }
        cout<<solve()<<"\n";
    }
    
    return 0;
}