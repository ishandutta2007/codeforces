#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int MAXN = 3e6 + 5;
int prime[MAXN], ct[MAXN], pidx[MAXN];
 
void sieve() {
    int idx = 1;
    for(int p = 2; p < MAXN; p++) {
        if(prime[p]) continue;
        pidx[p] = idx++;
        for(int q = p; q < MAXN; q += p)
            if(!prime[q]) prime[q] = p;
    }
}
 
int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
 
    sieve();
    int n;
    vector<int> res;
    cin >> n;
    for(int i = 0; i < 2*n; i++) {
        int x;
        cin >> x;
        ct[x]++;
    }
    for(int k = MAXN - 844; k >= 2; k--) {
        if(ct[k]) {
            if(prime[k] == k) {
                //cout << pidx[k] << '\n';
                ct[pidx[k]] -= ct[k];
                for(int i = 0; i < ct[k]; i++) res.push_back(pidx[k]);
            }
            else {
                //cout << k << '\n';
                ct[k / prime[k]] -= ct[k];
                for(int i = 0; i < ct[k]; i++) res.push_back(k);
            }
        }
        ct[k] = 0;
    }
    for(auto x : res)
        cout << x << " ";
    cout << '\n';
}