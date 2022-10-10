#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
 
    int v[3], d;
    cin >> v[0] >> v[1] >> v[2] >> d;
    int ans = 0;
    sort(v, v + 3);
    if(v[2] < v[1] + d) ans += (v[1] + d - v[2]);
    if(v[0] > v[1] - d) ans += (v[0] - (v[1] - d));
    cout << ans << '\n';   
}