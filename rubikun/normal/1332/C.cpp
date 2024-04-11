#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200001,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N,K;cin>>N>>K;
        string S;cin>>S;
        int ans=0;
        
        if(K%2==0){
            for(int i=0;i<K/2;i++){
                vector<int> cnt(26);
                for(int j=0;j<N/K;j++){
                    cnt[S[j*K+i]-'a']++;
                    cnt[S[(j+1)*K-1-i]-'a']++;
                }
                sort(all(cnt));
                ans+=N/K*2-cnt[25];
            }
        }else{
            for(int i=0;i<(K-1)/2;i++){
                vector<int> cnt(26);
                for(int j=0;j<N/K;j++){
                    cnt[S[j*K+i]-'a']++;
                    cnt[S[(j+1)*K-1-i]-'a']++;
                }
                sort(all(cnt));
                ans+=N/K*2-cnt[25];
            }
            
            vector<int> cnt(26);
            for(int j=0;j<N/K;j++){
                cnt[S[j*K+K/2]-'a']++;
            }
            sort(all(cnt));
            ans+=N/K-cnt[25];
        }
        
        cout<<ans<<"\n";
    }
}