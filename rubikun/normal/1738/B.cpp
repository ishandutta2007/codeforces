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
        ll N,K;cin>>N>>K;
        vector<ll> S(K);
        for(int i=0;i<K;i++) cin>>S[i];
        if(K==1){
            cout<<"Yes\n";
            continue;
        }
        vector<ll> T(K-1);
        for(int i=0;i<K-1;i++) T[i]=S[i+1]-S[i];
        
        if(N==K){
            bool ok=true;
            ok&=(S[0]<=T[0]);
            for(int i=0;i+1<K-1;i++) ok&=(T[i]<=T[i+1]);
            if(ok) cout<<"Yes\n";
            else cout<<"No\n";
            continue;
        }
        
        bool ok=true;
        for(int i=0;i+1<K-1;i++) ok&=(T[i]<=T[i+1]);
        
        ll X=T[0];
        ll mae=N-K+1;
        if(X*mae<S[0]) ok=false;
        
        if(ok) cout<<"Yes\n";
        else cout<<"No\n";
    }
}