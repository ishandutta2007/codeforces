#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200003,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,K;cin>>N>>K;
    string S;cin>>S;
    bool ok=true;
    
    for(int i=K;i<N;i++){
        if(S[i-K]<S[i]) ok=false;
        if(S[i-K]>S[i]) break;
    }
    
    if(!ok){
        S[K-1]++;
        for(int i=K-1;i>=0;i--){
            if(S[i]==':'){
                S[i]='0';
                S[i-1]++;
            }
        }
    }
    
    for(int i=0;i<K;i++){
        for(int j=i;j<N;j+=K){
            S[j]=S[i];
        }
    }
    
    cout<<N<<endl;
    cout<<S<<endl;
}