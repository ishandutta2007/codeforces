//https://codeforces.com/problemset/problem/508/B
//undefined
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    string s;
    cin>>s;
    int n=s.length();
    for(int i=0;i<n-1;i++){
        if((s[i]-'0')%2==0 && s[i]<s[n-1]) {s[i]=s[n-1]+s[i] -(s[n-1]=s[i]);break;}
    }
   if((s[n-1]-'0')%2==0) {cout<<s<<"\n";return 0;}
   else {
       for(int i=n-2;i>=0;i--){
           if((s[i]-'0')%2==0){
             s[i]=s[n-1]+s[i] -(s[n-1]=s[i]);break;}
       }
   }
   if((s[n-1]-'0')%2==0) cout<<s<<"\n";
   else cout<<"-1\n";
}