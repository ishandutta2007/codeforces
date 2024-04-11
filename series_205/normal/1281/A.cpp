#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;

int t;
string s;

int main(){
    cin>>t;
    while(t--){
        cin>>s;
        char c=s[s.size()-1];
        if(c=='o')cout<<"FILIPINO\n";
        if(c=='u')cout<<"JAPANESE\n";
        if(c=='a')cout<<"KOREAN\n";
    }
}