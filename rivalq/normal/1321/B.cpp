//https://codeforces.com/contest/1321/problem/B
#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int n;cin>>n;
    int b[n];
    for(int i=0;i<n;i++)cin>>b[i];
   map<int,int> mp;
   for(int i=0;i<n;i++){
         mp[b[i]-i]+=b[i];
    }
    int ma=0;
    for(auto i:mp){
        ma=max(ma,i.second);
    }
    cout<<ma<<endl;
}