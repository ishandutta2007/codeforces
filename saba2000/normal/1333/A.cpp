#include<bits/stdc++.h>
using namespace std;
main(){

    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin >> n >> m;
        for(int i = 1;i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(i == 1 && j < m) cout<<'W';
                else cout<<'B';
            }
            cout<<endl;
        }
    }
}