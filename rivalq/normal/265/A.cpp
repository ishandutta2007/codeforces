#include<bits/stdc++.h>
using namespace std;
int main(){
    string s,t;
   
    cin>>s>>t;
     int n=s.length();
    int j=0;
    for(int i=0;t[i]!='\0';i++){
       if(s[j]==t[i] && j<n) j++;
    }
    
    cout<<j+1<<endl;
}