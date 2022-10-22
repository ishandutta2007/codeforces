#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int n,k; cin>>n>>k;
    if(n>=k)cout<<(k-1)/2<<endl;
    else if(2*n>=k)cout<<(n-(k-n)+1)/2;
    else cout<<0<<endl;
}