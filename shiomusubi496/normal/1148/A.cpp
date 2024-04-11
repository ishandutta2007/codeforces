#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int a,b,c; cin>>a>>b>>c;
    if(a<b)cout<<a*2+1+c*2<<endl;
    else if(a>b)cout<<b*2+1+c*2<<endl;
    else cout<<a+b+c*2<<endl;
}