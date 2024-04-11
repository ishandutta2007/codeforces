#include<bits/stdc++.h>
using namespace std;
int a[109],b[109],c[109],p[109];
main(){
    int t;
    cin>>t;
    while(t--){

        int n;
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
         for(int i = 1; i <= n; i++){
            cin >> b[i];
        }
         for(int i = 1; i <= n; i++){
            cin >> c[i];
        }
        for(int i = 1; i <= n; i++){
            p[i] = a[i];
            if(p[i] == p[i-1] || (i == n && p[i] == p[1])) p[i] = b[i];
            if(p[i] == p[i-1] || (i == n && p[i] == p[1])) p[i] = c[i];
        }
        for(int i = 1; i <= n; i++)
            cout<<p[i]<<" ";
        cout<<endl;
    }

}