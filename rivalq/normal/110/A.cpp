#include<bits/stdc++.h>
using namespace std;
bool check( int n){
  if (n==7 || n==4){
      return true;
  }
  return false;
 
}
int main(){
    string s;
    cin >>s;
  long  int c=0;
    for(int i=0;s[i]!='\0';i++){
        if (s[i]=='4' || s[i]=='7'){
            c++;
        }
    }
    if (check(c)){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;
}