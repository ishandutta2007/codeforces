#include<bits/stdc++.h>
using namespace std;
int h1,h2,a,b,ans;
int main(){
    cin>>h1>>h2;
    cin>>a>>b;
    if(a<=b&&h1+a*8<h2){
        cout<<-1;
        return 0;
    }
    if(h1+8*a>=h2){
        cout<<0;
        return 0;
    }
    h1+=8*a;
    h1-=12*b;
    ans++;
    while(h1<h2){
        h1+=12*a;
        if(h1>=h2){
            cout<<ans;
            return 0;
        }
        h1-=12*b;
        ans++;
    }
    cout<<ans;
    return 0;
}