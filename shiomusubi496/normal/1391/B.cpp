#include<bits/stdc++.h>
using namespace std;
int main(){
    int Q;
    cin>>Q;
    while(Q--){
        int H,W;
        cin>>H>>W;
        vector<string> A(H);
        for(string &S:A)cin>>S;
        int ans=0;
        for(int i=0;i<H-1;i++){
            if(A[i][W-1]=='R')ans++;
        }
        for(int i=0;i<W-1;i++){
            if(A[H-1][i]=='D')ans++;
        }
        cout<<ans<<endl;
    }
}