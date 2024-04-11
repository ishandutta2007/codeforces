#include <bits/stdc++.h>
using namespace std;
int main(){
    string str;
    cin>>str;
    int len=str.size();
    int pos;
    int flag=0;
    int num0=0,num1=0;
    for(int i=0;i<len;i++){
      if(str[i]=='2'&&flag==0){
        flag=1;
        pos=i;
      }
      if(str[i]=='1') num1++;
      if(str[i]=='0'&&flag==0) num0++;
    }
    for(int i=0;i<num0;i++){
      cout<<"0";
    }
    for(int i=0;i<num1;i++){
      cout<<"1";
    }
    if(flag==1){
      for(int i=pos;i<len;i++){
        if(str[i]=='1') continue;
        cout<<str[i];
      }
    }
    cout<<endl;
    return 0;
}