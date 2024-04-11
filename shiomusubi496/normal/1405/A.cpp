#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int Q;
    cin>>Q;
    while(Q--){
        int N;
        cin>>N;
        vector<int> A(N);
        for(int &i:A)cin>>i;
        for(int i=N-1;i>=0;i--)cout<<A[i]<<(i?' ':'\n');
    }
}