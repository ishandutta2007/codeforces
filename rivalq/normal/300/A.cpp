#include<bits/stdc++.h>
using namespace std;
int main(){
    int m;
    cin>>m;
    int n=0,p=0,z=0,t;
    vector<int> pos,neg,zer;
    for(int i=0;i<m;i++){
        cin>>t;
        if(t>0) {p++; pos.push_back(t);}
        if(t<0) {n++; neg.push_back(t);}
        if(t==0) {z++; zer.push_back(0);}
    }
    if(n%2==0){
        if(p==0){
           pos.push_back(neg[n-1]);pos.push_back(neg[n-2]);
           p=2;n-=2;neg.pop_back(); neg.pop_back();
           zer.push_back(neg[n-1]);neg.pop_back();n--;z++;
        }
        else{
             zer.push_back(neg[n-1]);neg.pop_back();n--;z++;
        }

    }
    else if(p==0){
            pos.push_back(neg[n-1]);pos.push_back(neg[n-2]);
            p=2;n-=2;neg.pop_back(); neg.pop_back();
        }


     cout<<n<<" ";
     for(int i=0;i<n;i++){
         cout<<neg[i]<<" ";
     } 
     cout<<'\n'<<p<<" ";
     for(int i=0;i<p;i++){
         cout<<pos[i]<<" ";
     }
     cout<<'\n'<<z<<" ";
     for(int i=0;i<z;i++){
         cout<<zer[i]<<" ";
     }        
   cout<<endl; 
}