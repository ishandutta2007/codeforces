#include<bits/stdc++.h>
#define ll long long
using namespace std;
main(){
    int t;
    cin >>t ;
    while(t--){
        ll x,y,a,b;
        cin>>x>>y>>a>>b;
        if(b > 2*a) cout<<(abs(x)+abs(y)) * a << endl; else
        cout << min(abs(x), abs(y)) * b + (max(abs(x), abs(y)) - min(abs(x), abs(y))) * (a)<<endl;
    }
}