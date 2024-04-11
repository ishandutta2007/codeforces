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
const int mod=1000000007,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N,QQ;cin>>N>>QQ;
        string S;cin>>S;
        while(QQ--){
            int l,r;cin>>l>>r;
            l--;
            bool ok=false;
            for(int i=0;i<l;i++) if(S[i]==S[l]) ok=true;
            for(int i=r;i<N;i++) if(S[i]==S[r-1]) ok=true;
            
            if(ok) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}