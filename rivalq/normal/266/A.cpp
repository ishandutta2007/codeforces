#include<bits/stdc++.h>
using namespace std;
int main(){

      int n;
      cin>>n;
    string s;
    cin >>s;
    char t;
    int count=0;
    for(int i=0;i<n;i++){
    if(i==0){
      t=s[i];
    }
    else{
        if(s[i]==t){
            count++;
        }
        else{
            t=s[i];
        }

    }


    }
        cout<<count<<endl;

}