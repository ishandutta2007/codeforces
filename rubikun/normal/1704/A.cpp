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
        int N,M;cin>>N>>M;
        string S,T;cin>>S>>T;
        bool f=true;
        for(int i=1;i<M;i++){
            f&=(S[N-M+i]==T[i]);
        }
        
        bool deta=false;
        for(int i=0;i<=N-M;i++){
            if(S[i]==T[0]) deta=true;
        }
        
        if(deta&&f) cout<<"YES\n";
        else cout<<"NO\n";
    }
}