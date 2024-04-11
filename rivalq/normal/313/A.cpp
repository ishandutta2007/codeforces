#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n>=0){
        cout<<n;
    }
    else{
        int t=-n;
        int t1=t/10;
        int t2=(t/100)*10+t%10;
        t1=-t1;
        t2=-t2;
        int k=(t1>t2)?t1:t2;
        cout<<k;

    }
}