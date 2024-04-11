#include<bits/stdc++.h>
using namespace std;
int a[109];
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i =0 ;i < n;i++)
            cin >> a[i];
        int ok = 0;
        for(int j = 1; j <(1<<n); j++){
            for(int x = j; x; x = (x - 1)&j){
                int s = 0;
                for(int k = 0; k < n; k++)
                    if((1<<k)&j) {
                        if((1<<k) & x) s+=a[k];
                        else s -= a[k];
                    }
                if(s == 0) ok = 1;
            }
        }

        if(ok) cout<<"YES"<<endl; else cout <<"NO"<<endl;

    }

}