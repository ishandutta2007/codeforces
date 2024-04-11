#include<bits/stdc++.h>
#define ll long long
using namespace std;
main(){
    int t;
    cin>>t;
    while(t--){
        ll xa,ya,xb,yb;
        cin>>xa>>ya>>xb>>yb;
        ll dx = xb - xa, dy = yb - ya;
            cout << dx * dy + 1 << endl;

    }
}