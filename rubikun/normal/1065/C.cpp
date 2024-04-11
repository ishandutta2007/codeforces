#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100003,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N,K;cin>>N>>K;
    vector<int> A(N);
    for(int i=0;i<N;i++) cin>>A[i];
    sort(all(A));
    
    for(int i=1;i<N;i++) A[i]-=A[0];
    A[0]=0;
    
    vector<int> cnt(200001);
    for(int i=0;i<N;i++) cnt[A[i]]++;
    
    for(int i=199999;i>=0;i--) cnt[i]+=cnt[i+1];
    
    int ans=0,sum=0;
    
    for(int i=200000;i>=1;i--){
        if(sum+cnt[i]<=K) sum+=cnt[i];
        else{
            ans++;
            sum=cnt[i];
        }
    }
    
    if(sum>0) ans++;
    
    cout<<ans<<endl;
}