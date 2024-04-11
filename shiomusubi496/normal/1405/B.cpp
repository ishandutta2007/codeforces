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
        int m=0;
        for(int i=0;i<N;i++){
            if(A[i]<0)continue;
            int n=-1;
            m=max(m,i);
            for(int j=m+1;j<N;j++){
                if(A[j]<0){
                    n=j;
                    break;
                }
            }
            if(n==-1)break;
            A[n]+=A[i],A[i]=0;
            m=n-1;
        }
        int ans=0;
        for(int i:A)ans+=max(i,0LL);
        cout<<ans<<endl;
    }
}