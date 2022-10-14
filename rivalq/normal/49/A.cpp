#include<bits/stdc++.h>
using namespace std;
int iv(char a){
    char arr[6]={'a','e','i','o','u','y'};
    for(int i=0;i<6;i++){
        if(arr[i]==a) return 1;
    }
    return 0;
}
int main(){
    string s;
    getline(cin,s);
    int n=s.length();
    transform(s.begin(),s.end(),s.begin(),::tolower);
    for(int i=n-1;i>=0;i--){
       if(isalpha(s[i])){
           if(iv(s[i])) cout<<"YES"<<endl;
           else cout<<"NO"<<endl;
           break;
       }
   }

}