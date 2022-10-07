#include<bits/stdc++.h>
using namespace std;
main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        string w="";
        for(int i =0 ;i<s.size(); i+=2)
            w+=s[i];
        cout<<w<<endl;
    }

}