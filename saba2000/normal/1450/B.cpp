#include<bits/stdc++.h>
using namespace std;
int x[109],y[109];
main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        for(int i = 1; i <= n; i++)

            cin >> x[i]>>y[i];
        int ok = 0 ;
        for(int i = 1; i <= n; i++){
            int ok1 = 1;
            for(int j = 1; j <= n; j++){
                if(abs(x[i] - x[j]) + abs(y[i] - y[j]) > k)
                    ok1 = 0;
            }
            if(ok1) ok = 1;
        }
        if(ok) cout<<1<<endl;else cout<<-1<<endl;
    }



}