#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
map<ll, vector<int> > mp;

int n, a, b;
int x, v1, v2;

int main() {
    scanf("%d%d%d", &n, &a, &b);
    for(int i = 0; i < n; i++){
        scanf("%d%d%d", &x, &v1, &v2);
        ll cons = 1LL * a * v1 - v2;
        mp[cons].push_back(v1);
    }
    ll res = 0;
    for(auto p : mp){
        vector<int> V = p.second;
        sort(V.begin(), V.end());
        int cum = 0;
        for(int i = 0; i < V.size(); i++){
            if(i != 0 && V[i] != V[i-1]){
                cum = i;
            }
            res += cum;
        }
    }
    cout << res * 2;
}