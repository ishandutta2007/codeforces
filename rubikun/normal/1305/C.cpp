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
    
    int N,M;cin>>N>>M;
    if(N>M){
        cout<<0<<endl;
        return 0;
    }
    vector<int> cnt(M);
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    sort(all(A));
    
    ll ans=1;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(cnt[j]){
                ans*=(A[i]-j)%M;
                ans%=M;
            }
        }
        cnt[A[i]%M]++;
    }
    
    cout<<ans<<endl;
}