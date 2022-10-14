#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    int r1,c1,r2,c2;
    cin>>r1>>c1>>r2>>c2;
    int r,b,k;
    if(r1==r2||c1==c2) r=1;
    else r=2;
    if(abs(r1-c1)%2==abs(r2-c2)%2){
        if((r1-c1==r2-c2)||(r1+c1==r2+c2)) b=1;
        else b=2;
    }
    else b=0;
    k=max(abs(r1-r2),abs((c1-c2)));
   
    
    cout<<r<<" "<<b<<" "<<k<<endl;

}