#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll comb(int k){
    return 1LL * k * (k - 1) / 2;
}

int main(){
    int n,k;
    scanf("%d%d", &n, &k);
    int cur = 0;
    map<int, int> mp;
    mp[cur] ++;
    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        cur ^= x;
        cur = min(cur, (1 << k) - 1 - cur);
        mp[cur]++;
    }
    ll res = 1LL * n * (n + 1) / 2;
    for(auto p : mp){
//        cout << p.second << endl;
        res -= comb((p.second + 1) / 2) + comb(p.second / 2);
    }
    cout << res << endl;
}