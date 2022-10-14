//https://codeforces.com/contest/276/problem/B
#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int arr[26]={0};
    for(int i=0;s[i]!='\0';i++) arr[s[i]-97]++;
    int o=0;
    for(int i=0;i<26;i++){
        if(arr[i]%2==1) {o=1; break;}
    }
    if(s.length()%2==1 || o==0) cout<<"First\n";
    else cout<<"Second\n"; 
}