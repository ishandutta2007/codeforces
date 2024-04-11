#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    ll res = 0;
    for(int i = 0; i < n; ++i){
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        res += ((c - a + 1) * (d - b + 1));
    }
    cout << res;
    return 0;
}