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
    
    int Q;cin>>Q;
    while(Q--){
        int N,M,K;cin>>N>>M>>K;
        bool ok=true;
        vector<int> h(N);
        for(int i=0;i<N;i++) cin>>h[i];
        
        for(int i=0;i<N-1;i++){
            if(h[i]+M+K<h[i+1]){
                ok=false;
                break;
            }
            
            int diff=max(0,h[i+1]-K)-h[i];
            M-=diff;
        }
        
        if(ok) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    
}