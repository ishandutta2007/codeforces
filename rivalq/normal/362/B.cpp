//https://codeforces.com/problemset/problem/362/B
#include<bits/stdc++.h>
using namespace std;
#define lop(i,n,a)     for(int i=0;i<n;i+=a)

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    int s[m];lop(i,m,1) cin>>s[i];
    sort(s,s+m);
    if(s[0]==1||s[m-1]==n) {cout<<"NO\n";return 0;}
    int c=1,ma=0;
  
    lop(i,m,1){
    if(i==0) continue;
    else{
        if(s[i]-s[i-1]==1)c++;
        else {ma=max(ma,c);c=1;}
    }
   }
   ma=max(ma,c);
   if(ma>2) cout<<"NO\n";
   else cout<<"YES\n";
}