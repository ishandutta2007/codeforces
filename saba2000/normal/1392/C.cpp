#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[300009];

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i = 1; i <= n; i++){
            cin >>a[i];
        }
        int ans = 0;
        for(int i = 2; i<= n; i++)
            ans +=max(0ll, a[i-1] - a[i]);
        cout<<ans<<endl;
    }


}