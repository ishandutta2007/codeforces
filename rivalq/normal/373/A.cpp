#include<bits/stdc++.h>
using namespace std;
int fr(char arr[],char s){
    int c=0;
    for(int i=0;i<16;i++){
        if(s==arr[i]) c++;
    }
    return c;
}
int main(){
    char arr[16];
    int k;
    cin>>k;
    for(int i=0;i<16;i++) cin>>arr[i];
    for(int i=0;i<16;i++){
        if(arr[i]!='.'){
            if(fr(arr,arr[i])>2*k) {cout<<"NO"<<endl;return 0;}
        }
    }
      
    cout<<"YES"<<endl;
    return 0;
}