#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define debug(x) cerr << #x << " = " << x << ", line = " << __LINE__ << endl

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    setIO();
    int t; cin>>t;
    LL s = 1, k = 1;
    vector<LL> poss;
    while (s > 0 && s <= (1e18)) {
        poss.push_back(s);
        k += (k+1);
        s = (k*(k+1))/2;
    }
    while(t--) {
        LL x; cin>>x;
        int r = 0;
        for (int i = 0; i < poss.size(); i++)
            if (x >= poss[i]) {
                x -= poss[i];
                r++;
            }
        cout << r << endl;
    }
    
    return 0;
}