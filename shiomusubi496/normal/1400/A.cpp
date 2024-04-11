#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        string S;
        cin>>N>>S;
        for(int i=0;i<N;i++)cout<<S[i*2];
        cout<<endl;
    }
}