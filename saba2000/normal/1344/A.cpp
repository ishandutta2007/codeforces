#include<bits/stdc++.h>
using namespace std;
int a[200009];
int f[200009];
main(){
    int t;
    cin >>t ;
    while(t--){
        int n;
        cin >> n;
        for(int i =1; i <= n; i++){
            cin >> a[i];
            f[(i +a[i]%n + n)%n] = 1;
        }
        int ok = 1;
        for(int i= 0; i < n; i++)
            if(!f[i]) ok = 0;
        for(int i = 0; i < n; i++)
            f[i]= 0 ;
        if(ok) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

}