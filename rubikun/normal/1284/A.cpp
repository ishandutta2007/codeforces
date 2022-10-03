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
    
    int N,M;cin>>N>>M;
    vector<string> S(N),T(M);
    for(int i=0;i<N;i++) cin>>S[i];
    for(int i=0;i<M;i++) cin>>T[i];
    
    int Q;cin>>Q;
    while(Q--){
        int Y;cin>>Y;
        Y--;
        cout<<S[Y%N]<<T[Y%M]<<endl;
    }
}