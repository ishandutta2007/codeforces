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
    
    int QQ;cin>>QQ;
    while(QQ--){
        int N,C,Q;cin>>N>>C>>Q;
        string S;cin>>S;
        vector<ll> len(C+1);
        len[0]=N;
        vector<pair<ll,ll>> que(C+1);
        for(int i=1;i<=C;i++){
            ll l,r;cin>>l>>r;l--;
            len[i]=len[i-1]+r-l;
            que[i]=mp(l,r);
        }
        
        while(Q--){
            ll x;cin>>x;x--;
            for(int t=C;t>=1;t--){
                if(x>=len[t-1]){
                    x=(x-len[t-1]+que[t].fi);
                }else{
                    
                }
            }
            cout<<S[x]<<"\n";
        }
    }
}