#include<bits/stdc++.h>
using namespace std;
int main(){
    bool visited[26]={false};
    string s;
    cin>>s;
    int c=0;
    for(int i=0;i<s.length();i++){
        if(!visited[s[i]-97]){
          c++;
          visited[s[i]-97]=true;}
    }
    if(c%2==0)
    cout<<"CHAT WITH HER!"<<endl;
    else{
        cout<<"IGNORE HIM!"<<endl;
    }
}