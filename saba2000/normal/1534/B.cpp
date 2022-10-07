#include<bits/stdc++.h>
using namespace std;
int a[400009];
main(){
    int t;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        long long m = 1e9;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        long long ans = a[1];
        for(int i = 1; i <= n; i++){
            ans += abs(a[i] - a[i+1]);
            if(a[i] > a[i-1] && a[i] > a[i+1]){
                ans -= a[i] - max(a[i-1], a[i+1]);
            }
        }for(int i = 1; i <= n; i++)
        a[i] =0;
        cout<<ans<<endl;
    }
}