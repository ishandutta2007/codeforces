#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=998244353,MAX=300005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N,K,R,C;cin>>N>>K>>R>>C;R--;C--;
        R%=K;C%=K;
        vector<string> S(N,string(N,'.'));
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if((R+K-i%K)%K==(C+K-j%K)%K) S[i][j]='X';
            }
        }
        for(int i=0;i<N;i++) cout<<S[i]<<"\n";
    }
}