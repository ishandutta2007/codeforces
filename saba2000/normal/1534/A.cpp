#include<bits/stdc++.h>
using namespace std;
main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n>> m;
        int ok1 = 1, ok2 = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                char c;
                cin >>c;
                int x;
                if(c == 'R') x = 1; else
                    if(c == 'W') x = 0;
                else continue;
                if(x == (i+j)%2) ok1 = 0;
                else ok2 = 0;
            }
        }
        if(ok2){
            cout<<"YES"<<endl;
            for(int i =0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if((i+j)%2) cout<<'R';
                    else cout<<'W';
                }
                cout<<endl;
            }
        }
        else  if(ok1){
            cout<<"YES"<<endl;
            for(int i =0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if((i+j)%2) cout<<'W';
                    else cout<<'R';
                }
                cout<<endl;
            }
        }
        else cout<<"NO"<<endl;
    }
}