#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int i1=0,i2=0,il=0,ir=0;
    for(int i=0;i<n;i++){
        if(s[i]=='R'){
            i1=i;
            break;
        }
    }
    for(int i=i1;i<n;i++){
        if(s[i]=='L'){
            i2=i;
            break;
        }
    }
    for(int i=n-1;i>=0;i--){
       if(s[i]=='L'){
          il=i;
          break;
       }
       if(s[i]=='R'){
           ir=i;
           break;
       }
    }
    if(i2!=0 && i1!=0)cout<<i1+1<<" "<<i2<<endl;
    else if(i2==0) cout<<i1+1<<" "<<ir+2<<endl;
    else if(i1==0) cout<<il+1<<" "<<i2<<endl;
    
}