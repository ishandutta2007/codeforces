#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[300009];

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        long long k;
        cin>>n>>k;
        if(k % 2 ==0) k=2;
        else k = 1;
        int d = -1e9;
        for(int i = 1; i <= n; i++){
            cin >>a[i];
            d = max(d, a[i]);
        }
        int M = -1e9;
        for(int i = 1; i <= n; i++){
            a[i] = d - a[i],
            M =max(M, a[i]);
        }
        if(k ==2)
         for(int i = 1; i <= n; i++){
            a[i] = M - a[i];
        }
        for(int i =1; i <= n; i++)
        cout<<a[i]<<" ";
        cout<<endl;
    }


}