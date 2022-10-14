#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int u=2*pow(10,9);
    int l=-pow(10,9)*2;
    while(n--){
    string s;int y;char b; 
    cin>>s>>y>>b;
    if((s==">=" && b=='Y') || (s=="<" && b=='N')) l=max(y,l);
    else if((s==">" && b=='Y') ||(s=="<=" && b=='N')) l=max(y+1,l);
    else if((s==">=" && b=='N')||(s=="<" && b=='Y')) u=min(y-1,u);
    else if((s==">" && b=='N'||(s=="<=" && b=='Y'))) u=min(y,u);
}
if(l<=u){
    cout<<l<<endl;
}
else{
    cout<<"Impossible"<<endl;
}

}