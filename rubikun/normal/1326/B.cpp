#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<ll> B(N);
    for(int i=0;i<N;i++) cin>>B[i];
    
    vector<ll> ans(N);
    ans[0]=B[0];
    ll ma=ans[0];
    
    for(int i=1;i<N;i++){
        ans[i]=B[i]+ma;
        ma=max(ma,ans[i]);
    }
    
    for(int i=0;i<N;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}