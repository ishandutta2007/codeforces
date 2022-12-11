#include <bits/stdc++.h>
using namespace std;
int n,k,x;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>k;
        x=x|k;
    }
    if(x)cout<<"HARD"<<endl;
    else cout<<"EASY"<<endl;
    return 0;
}