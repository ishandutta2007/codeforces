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
const int mod=998244353,MAX=300005,INF=1<<29;

int main() {
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        string S;cin>>S;
        int N=si(S);
        int cn0=0,cn1=0;
        for(int i=0;i<N;i++){
            if(S[i]=='0') cn0++;
        }
        cn1=N-cn0;
        if(cn0!=cn1) cout<<min(cn0,cn1)<<"\n";
        else cout<<cn0-1<<"\n";
    }
}