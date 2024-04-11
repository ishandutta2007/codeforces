#include<bits/stdc++.h>
using namespace std;
string rep(int d){
    string s="        ";
    s[2]='|';
    if(d<5){
        for(int i=3;i<8;i++) s[i]='O';
        s[3+d]='-';s[0]='O';s[1]='-';
    }
    else{
         for(int i=3;i<8;i++) s[i]='O';
         s[0]='-';s[1]='O'; s[d-2]='-';

    }
    return s;
}
int main(){
    int n;
    cin>>n;
    if(n==0) {cout<<rep(0)<<endl;return 0;}
    while(n!=0){
    cout<<rep(n%10)<<endl;
    n/=10;
    }
}