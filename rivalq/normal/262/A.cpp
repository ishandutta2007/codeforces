#include<bits/stdc++.h>
using namespace std;
int lucky(string s,int k){
    int c=0;
    for(int i=0;s[i]!='\0';i++){
        if(s[i]=='4'||s[i]=='7') c++;
        if(c>k) return 0;
    }
    return 1;
}
int main(){
    int n,k;
    cin>>n>>k;
   int count=0;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        if(lucky(s,k)){
          count++;
        }
    }
    cout<<count<<endl;
}