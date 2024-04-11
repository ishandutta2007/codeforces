#include<bits/stdc++.h>
#define ll long long
using namespace std;
main(){
    int t;
    cin >>t ;
    while(t--){
        string s;
        cin >> s;
        int ok = 1;
        for(int i = 0; i < (int)s.size() - 1; i++)
            if(s[i] != s[i+1]) ok = 0;
        if(ok){
            cout<<s<<endl;
        }
        else{
            for(int i = 0; i < s.size(); i++){
                cout<<"01";
            }
            cout<<endl;
        }
    }
}