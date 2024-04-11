#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    vector<int> num;
    string n="";

    for(int i=0;s[i]!='\0';i++){
        if(s[i]=='+'){
            int t=stoi(n);
            num.push_back(t);
            n="";
        }
        else{
            n=n+s[i];
        }
    }
    int t=stoi(n);
    num.push_back(t);
    sort(num.begin(),num.end());
    cout<<num[0];
    for(int i=1;i<num.size();i++){
        cout<<"+"<<num[i];
    }
}