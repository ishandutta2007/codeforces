#include<bits/stdc++.h>
using namespace std;
main(){
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin >> n >> x;
        int o =0 ,e=0;
        while(n--){
            int x;
            cin>>x;
            if(x&1) o++; else e++;
        }
        int ok = 0;
        for(int E = 0; E <=x;E++){
            if(E <= e && x - E <= o && (x - E) % 2 != 0){
                cout<<"YES"<<endl;
                ok = 1;
                break;}
        }
        if(!ok) cout<<"NO"<<endl;
    }

}