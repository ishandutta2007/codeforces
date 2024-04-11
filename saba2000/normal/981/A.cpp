#include<bits/stdc++.h>
using namespace std;
main(){
    string s;
    cin >> s;
    int fl = 1;
    int n= s.size();
    for(int i = 0; i < s.size(); i++){
        if(s[i] != s[n-i-1]) fl= 0;
    }
    if(fl ) {

        for(int i =1 ;i < s.size(); i++){
            if(s[i] !=s[i-1]) fl = 0;
        }
    if(fl) cout<<0<<endl;
    else cout<<s.size()-1<<endl;
    }
    else cout<<s.size()<<endl;

}