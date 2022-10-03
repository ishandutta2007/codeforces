#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const ll mod=998244353,MAX=200001,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N,K;cin>>N>>K;
    vector<int> A(N),S[MAX];
    for(int i=0;i<N;i++){
        cin>>A[i];
        int cnt=1;
        S[A[i]].push_back(0);
        while(A[i]){
            A[i]/=2;
            S[A[i]].push_back(cnt);
            cnt++;
        }
    }
    
    int ans=INF;
    
    for(int i=0;i<200001;i++){
        if(S[i].size()<K) continue;
        sort(all(S[i]));
        int sum=0;
        for(int j=0;j<K;j++){
            sum+=S[i][j];
        }
        ans=min(ans,sum);
    }
    
    cout<<ans<<endl;
}