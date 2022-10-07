#include<bits/stdc++.h>
using namespace std;
int a[400009],p[400009],f[400009];
long long mod=  1e9 + 7;
main(){
    int t;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
         for(int i = 1; i <= n; i++){
            int b;
            cin >> b;
            p[a[i]] = b;
        }
        long long ans = 1;
        for(int i = 1; i <= n; i++){
            if(f[i] == 0){
                ans = ans*2%mod;
                int x = p[i];
                while(1){
                    f[x] = 1;
                    x = p[x];
                    if(x == i) break;
                }
            }
        }
        cout<<ans<<endl;
        for(int i =1; i <= n; i++)
            a[i] = 0,p[i] =0,f[i] =0;

    }
}