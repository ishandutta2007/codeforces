#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin>>N;
    while(N--){
        int a;
        cin>>a;
        if(a==36)cout<<"YES\n6 10 15 5\n";
        else if(a==40)cout<<"YES\n6 10 15 9\n";
        else if(a==44)cout<<"YES\n6 10 15 13\n";
        else if(a>30)cout<<"YES\n6 10 14 "<<a-30<<endl;
        else cout<<"NO\n";
    }
}