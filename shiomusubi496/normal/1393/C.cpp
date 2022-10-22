#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int Q;
    cin>>Q;
    while(Q--){
        int n;
        cin>>n;
        vector<int> A(n,0);
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            A[a-1]++;
        }
        int mx=0,cnt=0;
        for(int i=0;i<n;i++){
            if(mx<A[i])mx=A[i],cnt=1;
            else if(mx==A[i])cnt++;
        }
        cout<<(n-mx-cnt+1)/(mx-1)<<endl;
    }
}