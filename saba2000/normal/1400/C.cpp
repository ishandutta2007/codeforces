#include<bits/stdc++.h>
#define ll long long
using namespace std;
int w[100009];
main(){
    ios_base::sync_with_stdio(false);
    ll t;
    cin>>t;
    while(t--){
        string s;
        int x;
        cin>>s>>x;
        for(int i = 0 ;i < s.size(); i++){
            w[i] = 0;
        }
        for(int i = 0; i< s.size(); i++){
            if(s[i] == '0') {
                if(i-x >= 0) w[i-x] = 1;
                if(i+x <s.size()) w[i+x] = 1;
            }
        }
        string s1;
        for(int i = 0 ;i < s.size(); i++){
            if(i-x>=0 && w[i-x] == 0) s1+='1';else
            if(i+x<s.size() && w[i+x] == 0) s1+='1'; else
            s1+='0';
        }

        if(s!=s1){
            cout<<-1<<endl;
        }
        else{
            for(int i = 0; i<s.size(); i++)
                cout<<1-w[i];
            cout<<endl;
        }
    }

}