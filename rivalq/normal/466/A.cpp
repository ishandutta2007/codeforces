#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,a,b;
    cin>>n>>m>>a>>b;

    
    if(a*m>=b){
        int x=(n%m)*a;
        if(x>b) x=b;
       cout<<(n/m)*b+x;
        }
    
    else {
        cout<<a*n;
    }
}