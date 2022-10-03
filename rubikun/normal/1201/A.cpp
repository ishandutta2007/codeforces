#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<17,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N,M;cin>>N>>M;
    vector<string> S(N);
    for(int i=0;i<N;i++){
        cin>>S[i];
    }
    
    vector<int> score(M);
    for(int i=0;i<M;i++){
        cin>>score[i];
    }
    
    int ans=0;
    
    for(int j=0;j<M;j++){
        vector<int> cnt(5,0);
        for(int i=0;i<N;i++){
            cnt[S[i][j]-'A']++;
        }
        sort(all(cnt));
        
        ans+=score[j]*cnt[4];
    }
    
    cout<<ans<<endl;
}