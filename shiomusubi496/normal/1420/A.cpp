#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int Q;
    cin>>Q;
    while(Q--){
        int n,a;
        cin>>n>>a;
        bool ok=false;
        for(int i=1;i<n;i++){
            int b;
            cin>>b;
            if(a<=b)ok=true;
            a=b;
        }
        puts(ok?"YES":"NO");
    }
}