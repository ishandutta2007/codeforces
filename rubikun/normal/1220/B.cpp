#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100003,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;cin>>N;
    vector<vector<ll>> A(2,vector<ll>(N));
    for(int i=0;i<2;i++){
        for(int j=0;j<N;j++){
            cin>>A[i][j];
        }
    }
    
    vector<ll> ans(N);
    ll left=0,right=1000000005;
    while(right-left>1){
        ll mid=(left+right)/2;
        if(mid*mid<=A[0][1]*A[0][2]/A[1][2]){
            left=mid;
        }else right=mid;
    }
    ans[0]=left;
    
    for(int i=1;i<N;i++){
        ans[i]=A[0][i]/ans[0];
    }
    
    for(int i=0;i<N;i++){
        if(i) cout<<" ";
        cout<<ans[i];
    }
    
    cout<<endl;
    
}