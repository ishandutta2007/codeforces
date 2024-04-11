#include <bits/stdc++.h>

using namespace std;


int main(){
    int t;
    cin>>t;
    long long x,y,p,q,v;
    for(int z=0;z<t;z++){
        cin>>x>>y>>p>>q;
        if(p==0 && x!=0 || q==1 && p==1 && x!=y)
            cout<<"-1\n";
        else if(p == 0 || q == 1 && p==1){
            cout<<"0\n";
        }
        else{
            v=max((x+p-1)/p,(y - x+q-p-1)/(q-p));
            cout<<v*q-y<<endl;
        }
    }
    return 0;
}