#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m; cin>>n>>m;
    string s,t; cin>>s>>t;
    if(s==t)return puts("YES"),0;
    else if(count(s.begin(),s.end(),'*')==0)return puts("NO"),0;
    int l=0,r=0;
    for(;s[l]==t[l];l++);
    for(;s[n-r-1]==t[m-r-1];r++);
    if(s[l]!='*' || s[n-r-1]!='*')puts("NO");
    else if(l+r<=m)puts("YES");
    else puts("NO");
}