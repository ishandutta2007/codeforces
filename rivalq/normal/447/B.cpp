//https://codeforces.com/problemset/problem/447/B
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    string s;int k,arr[26];
    cin>>s>>k;
    int l=s.length();
    for(int i=0;i<26;i++) cin>>arr[i];
    int ma=0;
    for(int i=0;i<26;i++){
        if(ma<arr[i]) ma=arr[i];
    }
    int f=0;
    for(int i=1;i<=l;i++){
      f+=arr[s[i-1]-97]*i;
    }
    int i=l+1;
    while(k--){
        f+=ma*i;
        i++;
    }
    cout<<f<<"\n";

}