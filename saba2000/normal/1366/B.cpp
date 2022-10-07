#include<bits/stdc++.h>
using namespace std;
main(){
    int t;
    cin>>t;
    while(t--){
        int n,x,m;
        cin>>n>>x>>m;
        int a = x, b = x;
        while(m--){
            int l,  r;
            cin >> l >> r;
            if(max(a,l) <= min(b,r)) {
                a = min(a, l);
                b = max(b, r);
            }
        }
        cout<<b-a+1<<endl;

    }
}