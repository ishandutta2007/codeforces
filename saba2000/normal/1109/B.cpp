#include<bits/stdc++.h>
using namespace std;
bool pal(string s){
    for(int i = 0; i < s.size(); i++)
        if(s[i] != s[s.size()-1-i]) return 0;
    return 1;
}
main(){
    string s;
    cin >> s;
    bool fl = 0;
    int n= s.size();
    for(int i = 1; i < n/2; i++){
        if(s[i] != s[i-1]) fl = 1;
    }
    if(!fl){
        cout <<"Impossible"<<endl;
        return 0;
    }
    for(int i = 1; i < n-1; i++){
        string a = "", b ="";
        for(int j = 0; j < n; j++)
            if(j < i) a += s[j];  else b +=s[j];
        if(b+a != s && pal(b+a)) {
            cout<<1<<endl;
            return 0;
        }
    }
    cout<<2<<endl;

}