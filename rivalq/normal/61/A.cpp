#include<bits/stdc++.h>
using namespace std;
int main(){
string x,y;
   cin >>x;
    cin >>y;
 char s[x.length()];

    for(int i =0 ;x[i]!='\0';i++){
        if(x[i]==y[i]){
            s[i]='0';
        }
        else{
            s[i]='1';
        }
    }

    for(int j=0 ; j<x.length();j++){
        cout<<s[j];
    }
    cout<<endl;
}