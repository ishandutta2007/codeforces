#include<bits/stdc++.h>
using namespace std;
int a[100009];
main(){
    int t;
    cin>>t;
    while(t--){

        int n;
        cin >> n;
        for(int i =1 ; i <= n; i++){
            cin >>a[i];
        }
        int mn = a[1];
        int ok = 1;
        for(int i =1; i <= n; i++){
            if(a[i-1] > a[i]) mn -= (a[i-1] - a[i]);
            if(mn < 0) ok = 0;

        }
        cout << (ok ? "YES" : "NO")<<endl;
    }
}