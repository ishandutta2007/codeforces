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
        ll S,N,K;cin>>S>>N>>K;
        if(K>S){
            cout<<"NO\n";
        }else if(K==S){
            cout<<"YES\n";
        }else if(S==N){
            cout<<"YES\n";
        }else{
            ll need=(N/K)*K*2+N%K;
            if(need<=S) cout<<"NO\n";
            else cout<<"YES\n";
        }
    }
}