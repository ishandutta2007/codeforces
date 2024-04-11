#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int N;
    cin>>N;
    vector<int> A(N);
    for(int &i:A)cin>>i;
    sort(A.begin(),A.end());
    int ans=0;
    for(int i:A)ans+=i;
    ans-=N;
    for(int i=2;true;i++){
        int cnt=0;
        for(int k=0,m=1;k<N;k++,m*=i){
            cnt+=abs(A[k]-m);
            if(cnt>ans)break;
        }
        if(cnt==-1 || ans<cnt)break;
        ans=min(ans,cnt);
    }
    cout<<ans<<endl;
}