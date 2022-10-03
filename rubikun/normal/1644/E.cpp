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
const int mod=1000000007,MAX=300005;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        ll N;cin>>N;
        string S;cin>>S;
        int M=si(S);
        string T=S;sort(all(T));
        if(T[0]==T[M-1]){
            cout<<N<<"\n";
            continue;
        }
        int cn=0;
        for(int i=0;i+1<M;i++){
            cn++;
            if(S[i]!=S[i+1]) break;
        }
        ll ans=N*N;
        ans-=(N-1)*cn;
        ll h=0,w=0;
        for(int i=cn;i<M;i++){
            if(S[i]=='D') h++;
            else w++;
        }
        ans-=(h+1)*(w+1)-(M-cn+1);
        
        cout<<ans<<"\n";
    }
}