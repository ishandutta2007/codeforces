#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200009],s[200009];
main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll S = 0;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            s[i] = a[i] - s[i-1];
            if(i % 2 == 1) S += a[i];
        }
        //s[i] - s[j]
        ll me = 0, mo = -1e18;
        ll ans = 0;
        for(int i = 1; i <= n; i++){
            if(i % 2 == 0){
                ans = max(ans, s[i] - me);
                me = min(me, s[i]);
            }
            else{
                ans = max(ans, mo - s[i]);
                mo = max(mo, s[i]);
            }
        }
        cout<<ans + S << endl;
    }
}