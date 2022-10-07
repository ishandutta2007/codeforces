
#include<bits/stdc++.h>
using namespace std;
int a[100009];
main(){
    int t;
    cin >>t;
    while(t--){
        int n, u,v;
        cin>>n>> u>>v;
        for(int i =1; i <= n; i++){
            cin >> a[i];
        }
        int ok1 = 1,ok2 = 1;
        for(int i = 2; i <= n; i++){
            if(a[i] != a[i-1]) ok1 = 0;
            if(abs(a[i] - a[i-1]) > 1) ok2 = 0;
        }
        if(ok1){
            cout << min(2*v, u+v) << endl;
        }
        else if(!ok2){
            cout<<0<<endl;
        }
        else{
            cout << min(u,v)<<endl;
        }
    }
}