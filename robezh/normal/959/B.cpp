#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,k,m, si;
string s;
string str[100050];
int cost[100050];
int gro[100050];
map<string, int> mp;

int main() {
    cin >> n >> k >> m;
    for(int i = 0; i < n; i++){
        cin >> str[i];
        mp[str[i]] = i;
    }
    for(int i = 0; i < n; i++) cin >> cost[i];

    for(int i = 0; i < k; i++){
        cin >> si;
        int mn = (int)1e9 + 50;
        for(int i = 0; i < si; i++){
            cin >> gro[i];
            gro[i]--;
            mn = min(cost[gro[i]], mn);
        }
        for(int i = 0; i < si; i++) cost[gro[i]] = mn;
    }
    ll res = 0;
    for(int i = 0; i < m; i++){
        cin >> s;
        res += cost[mp[s]];
    }
    cout << res;
}