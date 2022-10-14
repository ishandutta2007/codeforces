#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >>s;
    int u=0,l=0;
    for (int i=0;s[i]!='\0';i++){
        if (isupper(s[i])){
            u++;
        }
        else{
            l++;
        }
    }
    if (l>=u){
        for(int k=0;k<l+u;k++){
            s[k]=tolower(s[k]);
        }}
     else{
          for(int k=0;k<l+u;k++){
            s[k]=toupper(s[k]);
        }

     }   
    cout<<s;
}