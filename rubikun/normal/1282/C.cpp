#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        ll N,T,A,B;cin>>N>>T>>A>>B;
        vector<pair<int,int>> S(N);
        for(int i=0;i<N;i++){
            cin>>S[i].second;
        }
        for(int i=0;i<N;i++){
            cin>>S[i].first;
        }
        sort(all(S));
        S.push_back({T+1,0});
        
        vector<ll> easy(N+1),hard(N+1);
        for(int i=1;i<=N;i++){
            easy[i]=easy[i-1];
            hard[i]=hard[i-1];
            
            if(S[i-1].second==0) easy[i]++;
            else hard[i]++;
        }
        
        int ans=0;
        
        for(int i=-1;i<N;i++){
            int cnt=i+1;
            ll sum=easy[i+1]*A+hard[i+1]*B;
            if(sum>S[i+1].first-1) continue;
            
            ll rem=S[i+1].first-1-sum;
            
            if(rem>=(easy[N]-easy[i+1])*A){
                cnt+=easy[N]-easy[i+1];
                rem-=(easy[N]-easy[i+1])*A;
                
                cnt+=min(hard[N]-hard[i+1],rem/B);
            }else{
                cnt+=rem/A;
            }
            
            ans=max(ans,cnt);
        }
        
        cout<<ans<<endl;
    }
}