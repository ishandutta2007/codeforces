#include<bits/stdc++.h>
using namespace std;
int ra(char arr[],char c){
    for(int i=0;i<9;i++){
        if(c==arr[i]) return i;
    }
}
int main(){
    char t;string f,s;
    cin>>t>>f>>s;
    char arr[9]={'6','7','8','9','T','J','Q','K','A'};
   
    if(f[1]==t && s[1]!=t) {
        cout<<"YES"<<endl;
    }
    else if(f[1]==s[1] && ra(arr,f[0])>ra(arr,s[0])){
         cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }

}