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
        if(A[0]+A[1]<=A[N-1])cout<<"1 2 "<<N<<endl;
        else puts("-1");
    }
}