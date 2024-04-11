#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n,m;
int a,b;
map<int, int> mp;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d%d", &a, &b);
        mp[a] = b;
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        scanf("%d%d", &a, &b);
        if(mp.count(a)) mp[a] = max(mp[a], b);
        else mp[a] = b;
    }
    ll res = 0;
    for(auto p : mp){
        res += p.second;
    }
    cout << res;
}