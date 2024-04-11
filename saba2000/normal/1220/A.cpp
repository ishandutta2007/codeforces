#include<bits/stdc++.h>
using namespace std;
main (){
    int n;
    cin>>n;
    string s;
    cin >> s;
    int o= 0,z=0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'n') o++;
    if(s[i] =='z') z++;
    }
    for(int i = 0; i < o; i++)
        cout<<1<<" ";
    for(int i = 0 ; i < z; i++)
        cout<<0<<" ";
}