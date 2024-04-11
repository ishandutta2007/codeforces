#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;

ll n;
string s;
vector<int>v;

int main(){
    cin>>n>>s;
    rep(i,n-2){
        if(s[i]!=s[i+1]){
            v.push_back(i+2);
            s[i+1]=(s[i+1]=='W'?'B':'W');
            s[i+2]=(s[i+2]=='W'?'B':'W');
        }
    }
    for(int i=n-1;i>=2;i--){
        if(s[i]!=s[i-1]){
            v.push_back(i-1);
            s[i-1]=(s[i-1]=='W'?'B':'W');
            s[i-2]=(s[i-2]=='W'?'B':'W');
        }
    }
    if(s[0]!=s[1])cout<<-1<<endl;
    else{
        cout<<v.size()<<endl;
        rep(i,v.size()){
            if(i)cout<<" ";
            cout<<v[i];
        }
        cout<<endl;
    }
    return 0;
}