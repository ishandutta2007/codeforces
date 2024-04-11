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
const int mod=998244353,MAX=300005;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        string S;cin>>S;
        bool f=true;
        for(int i=0;i<si(S);i++){
            bool g=false;
            if(i&&S[i-1]==S[i]) g=true;
            if(i+1<si(S)&&S[i]==S[i+1]) g=true;
            f&=g;
        }
        if(f) cout<<"YES\n";
        else cout<<"NO\n";
    }
}