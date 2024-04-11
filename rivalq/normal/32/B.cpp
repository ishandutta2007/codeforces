#include<bits/stdc++.h>
using namespace std;
int main(){

    string s;
    cin>>s;
    string t="";
    for(int i=0;s[i]!='\0';){
        if (s[i]=='.'){
            t=t+"0";
            i++;
        }
        if (s[i]=='-'){
            if (s[i+1]=='.'){
                t = t+"1";
            }
          else{
              t = t+"2";
          }
          i=i+2;
        }
    

    }
    cout<<t;
      

   
  return 0;


}