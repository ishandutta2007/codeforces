#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int Q;
    cin>>Q;
    while(Q--){
        int A,B;
        cin>>A>>B;
        if(A>=B)cout<<(A+B)%2<<endl;
        else cout<<B-A<<endl;
    }
}