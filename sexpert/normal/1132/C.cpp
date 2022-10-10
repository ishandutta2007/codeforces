#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
 
const int MAXN = 5005;
int amt[MAXN], swp[MAXN], ct1[MAXN], ct2[MAXN];
 
int main() {
    int n, q;
    cin >> n >> q;
    vector<ii> pairs(q);
    for(int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        swp[l]++;
        swp[r + 1]--;
        pairs[i] = ii{l, r};
    }
 
    int cu = 0, ini = 0;
    for(int i = 1; i <= n; i++) {
        cu += swp[i];
        amt[i] = cu;
    }
 
    int ans = 0;
 
    for(int i = 0; i < q; i++) {
        auto p1 = pairs[i];
        ini = 0;
        for(int x = p1.first; x <= p1.second; x++)
            amt[x]--;
        ct1[0] = 0;
        for(int x = 1; x <= n; x++) {
            ct1[x] = ct1[x - 1];
            if(amt[x] == 1)
                ct1[x]++;
            if(amt[x] > 0)
                ini++;
        }
        for(int j = 0; j < q; j++) {
            if(j == i)
                continue;
            auto p2 = pairs[j];
            int ex = ct1[p2.second] - ct1[p2.first - 1];
            ans = max(ans, ini - ex);
        }
        for(int x = p1.first; x <= p1.second; x++)
            amt[x]++;
    }
    cout << ans << endl;
}