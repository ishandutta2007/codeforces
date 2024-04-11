#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    string team1=s,team2;
    int t1=1,t2=0;
    for(int i=1;i<n;i++){
        cin>>s;
        if(s==team1) t1++;
        else {t2++; team2=s;} 
    }
    if(t1>t2) cout<<team1<<endl;
    else cout<<team2<<endl;
   
}