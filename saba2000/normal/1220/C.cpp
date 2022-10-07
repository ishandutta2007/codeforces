#include<bits/stdc++.h>
using namespace std;
int m[1009][1009];
main (){
    string s;
    cin >> s;
    char c ='z';
    for(int i= 0; i < s.size(); i++){
        if(s[i] <= c)  {c=s[i];  cout<<"Mike"<<endl;}
        else cout<<"Ann"<<endl;
    }
}