#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll a[55],b[55];
bool can[55];
int n,m;


ll get(int t){
    ll res = -2e18;
    can[t] = false;
    for(int i = 0; i < n; i++){
        if(can[i]){
            for(int j = 0; j < m; j++){
                res = max(res, a[i] * b[j]);
            }
        }
    }
    can[t] = true;
    return res;
}

int main(){
    fill(can, can+55, 1);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    ll res = 2e18;
    for(int i = 0; i < n; i++){
        res = min(res, get(i));
    }
    cout << res;


}