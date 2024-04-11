#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int even=0,odd=0;
    int o=0,e=0;
    for (int i=0;i<n;i++){
        int t;
        cin>>t;
        if(t%2==0)
        {even++;
         e=i+1;}
        else
        {
            odd++;
            o=i+1;
        }
        
    }
    if(odd==1){
    cout<<o<<endl;
    }
    else{
        cout<<e<<endl;
    }
}