#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    bool first=1;
    string old="";
    while(getline(cin,s)){
        bool amp=0;
        for (auto x:s){
            if (x!=' '){
                if (x=='#')amp=1;
                else amp=0;
                break;
            }
        }
        if (amp){
            if (!first)cout<<old<<endl;
            old="";
            cout<<s<<endl;
            first=1;
        } else {
            for (auto x:s)if (x!=' ')old+=x;
            first=0;
        }
    }
    if (!first)cout<<old<<endl;
}