#include<bits/stdc++.h>
using namespace std;
main(){
    int n;
    cin >> n;
    if(n % 2 == 0){
        cout <<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    for(int i = 0; i < n; i++){
        if(i % 2 == 0) cout<<2*i+1<<" ";
        else cout<<2*i+2<<" ";
    }
    for(int i = 0; i < n; i++){
        if(i % 2 == 0) cout<<2*i+2<<" ";
        else cout<<2*i+1<<" ";
    }
    cout<<endl;

}