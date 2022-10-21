//
// Created by 54173 on 5/19/2022.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int T; cin>>T;
    while(T--) {
        int n,m; cin>>n>>m;
        int r = 0, w = 0;
        for(int i=0;i<m;i++) {
            int a,b; cin>>a>>b;
            r = max(a,r);
            w = max(b,w);
        }
        if(r+w > n) {
            cout<<"IMPOSSIBLE\n";
        }
        else {
            for(int i=0;i<r;i++)
                cout<<"R";
            for(int i=r;i<n;i++)
                cout<<"W";
            cout<<"\n";
        }
    }
    return 0;
}