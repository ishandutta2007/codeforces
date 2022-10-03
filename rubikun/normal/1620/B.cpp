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
const int mod=998244353,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        ll W,H;cin>>W>>H;
        ll ans=0;
        for(int q=0;q<4;q++){
            int K;cin>>K;
            vector<ll> A(K);
            for(int i=0;i<K;i++) cin>>A[i];
            if(q<2) chmax(ans,(A.back()-A.front())*H);
            else chmax(ans,(A.back()-A.front())*W);
        }
        cout<<ans<<"\n";
    }
}