#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        string ret="";
        bool zero=0, one=0;
        for (int i=0;i<s.size();i++){
            if (s[i]=='0')zero=1;
            else one=1;
        }
        if (zero && one){
            for (int i=0;i<s.size();i++) ret+="01";
        } else {
            if (zero) for (int i=0;i<s.size();i++) ret+="0";
            else for (int i=0;i<s.size();i++) ret+="1";
        }
        cout<<ret<<endl;

    }
}