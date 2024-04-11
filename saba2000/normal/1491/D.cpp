
#include<bits/stdc++.h>
using namespace std;
int a[100009];
int N[100009];
int P[100009];
main(){
    int q;
    cin >> q;
    while(q--){
        int u, v;
        cin >> u >> v;

        int ok = 1;
        int U = 0, V = 0;
        for(int i = 0; i < 30; i++){
            if((1<<i) & u) U++;
            if((1<<i) & v) V++;
            if(V > U) ok = 0;
        }
        if(ok && v >= u) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}