#include<bits/stdc++.h>
#define ll long long
using namespace std;
main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n%2==0){
            n/=2;
            while(n--)
                cout<<1;
        }
        else{
            n-=3;
            cout<<7;
            n/=2;
            while(n--)
                cout<<1;
        }
        cout<<endl;
    }
}