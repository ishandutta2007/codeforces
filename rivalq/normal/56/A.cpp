#include<bits/stdc++.h>
using namespace std;
int check(string arr[],string s){
    for(int i=0;i<11;i++){
        if(arr[i]==s) return 1;
    }
    return 0;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;string s;int b=0,c=0,t;
    cin>>n;
    string arr[11]={"ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE"};
    for(int i=0;i<n;i++){
       b=0; 
       cin>>s;
       for(int j=0;s[j]!='\0';j++){
         if(!isdigit(s[j])) {
             b=1;break;
         }
       }
        if(b==0){
         t=stoi(s);
         if(t<18) c++;
       }
       else if(check(arr,s)){
         c++;
       }
    }
    cout<<c<<endl;
}