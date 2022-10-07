#include<bits/stdc++.h>
#define ll long long
using namespace std;
main(){
    int t;
    cin >>t;
    while(t--){
        long long a,m;
        cin>>a>>m;
        long long x = m / __gcd(a,m),  y = x;
        for(ll j = 2; j*j <= x; j++){
            if(x % j == 0) {y = y / j * (j - 1);
            while(x%j==0) x/= j;}
        }
        if(x > 1) y = y / x *( x-1);
        cout<<y<<endl;
    }
}