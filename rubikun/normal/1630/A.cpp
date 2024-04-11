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
const ll INF=1LL<<61;

int main() {
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N,K;cin>>N>>K;
        vector<pair<int,int>> ans(N/2);
        for(int i=0;i<N/2;i++) ans[i]=mp(i,N-1-i);
        if(N==4&&K==3){
            cout<<-1<<"\n";
            continue;
        }else if(K<N/2){
            swap(ans[0].se,ans[K].se);
        }else if(K!=N-1){
            swap(ans[0].se,ans[N-1-K].fi);
        }else{
            ans[0]=mp(0,2);
            ans[1]=mp(N-1,N-2);
            ans[2]=mp(1,N-3);
        }
        
        for(int i=0;i<N/2;i++) cout<<ans[i].fi<<" "<<ans[i].se<<"\n";
        
    }
    
}