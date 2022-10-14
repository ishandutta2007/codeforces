#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n = s.length();
    transform(s.begin(), s.end(), s.begin(), ::tolower); 
    string s1="";
    for(int i=0;s[i]!='\0';i++){
        if(!(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='y')){
           s1=s1+s[i]; 
         }

    }
    for (int i=0;s1[i]!='\0';i++){
        cout<<"."<<s1[i];
    }
  


}